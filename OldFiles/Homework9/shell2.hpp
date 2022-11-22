#include <memory>
#include <functional>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iostream>

namespace details {
    static unsigned long long COUNTER = 0;
}

template <typename T>
class shell;

template <typename Res, typename... Args>
class shell<Res(Args...)> {

public:
    template <typename FunctionObject> requires std::is_invocable_v<FunctionObject, Args...>
    shell(FunctionObject fo, std::string fname)
        : fun{new Derived<FunctionObject>(fo)},
        filename{fname}
    { 
    #ifdef DEBUG
        std::cout << "CTOR\n";
    #endif
    }

    shell() = default;
    
    shell(const shell& other) : fun{other.fun->get_copy()}, filename{other.Filename} {
        //TODO
    #ifdef DEBUG
        std::cout << "COPY CTOR\n";
    #endif
    }
    
    shell(shell&& other) {
    #ifdef DEBUG
        std::cout << "MOVE CTOR\n";
    #endif
        std::swap(fun, other.fun);
        std::swap(filename, other.filename);
    }
    
    shell& operator=(const shell& rhs) {
    #ifdef DEBUG
        std::cout << "COPY =\n";
    #endif
        
        //allocating memory
        auto tmp = rhs.fun->get_copy();
        
        if (fun != nullptr) fun->destroy();
        fun = tmp;
        filename = rhs.filename;
        return *this;
    }

    shell& operator=(shell&& rhs) {
    #ifdef DEBUG
        std::cout << "MOVE =\n";
    #endif
        std::swap(fun, rhs.fun);
        std::swap(filename, rhs.filename);
        return *this;
    }

    Res operator()(Args&&... args) {
        Res res = (*fun)(std::forward<Args>(args)...);
        ++details::COUNTER;
        std::fstream outfile;
        outfile.open(filename, outfile.out | std::ios::app);
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        outfile << ctime(&t) << ' ';
        outfile << details::COUNTER << ". Function " << typeid(*this).name() << " called with arguments: (";
        print_args(outfile, args...);
        outfile << ')' << " Result: " << res << '\n';
        outfile.close();
        outfile.clear();
        return res;
    }

    ~shell() {
        if (fun != nullptr) fun->destroy();
        delete fun;
#ifdef DEBUG
        std::cout << "DTOR\n";
#endif
    };


private:
    struct Base {
        virtual Res operator()(Args&&...) = 0;
        virtual Base* get_copy() = 0;
        virtual void destroy() = 0;
        virtual ~Base() = default;
    };

    template <typename F>
    struct Derived : Base {
        F callable;
        Derived(const F& callable_)
            : callable{callable_}
        {}
        Derived(const Derived& other) : callable{other.callable} {}
        Base* get_copy() override { 
            return new Derived<F>{callable};
        }

        Res operator()(Args&&... args) override {
            return std::invoke(callable, std::forward<Args>(args)...);
        }
        void destroy() override { 
            //callable.~F();
#ifdef DEBUG
            std::cout << "CALLABLE DTOR\n";
#endif
        }
        ~Derived() {}
    };

private:
    void print_args(std::fstream& outfile) {}

    template <typename T> void print_args(std::fstream& outfile, T&& t) {
        outfile << std::forward<T>(t);
    }
    
    template <typename First, typename... Rest>
    void print_args(std::fstream& outfile, First&& first, Rest&&... rest) {
        outfile << std::forward<First>(first) << ", ";
        print_args(outfile, rest...); 
    }

    Base* fun = nullptr;
    mutable std::string filename;

public:
    void change_filename(const std::string& newfilename) const {
        filename = newfilename;
    }
};