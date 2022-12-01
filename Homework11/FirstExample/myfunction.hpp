#include <functional>

namespace my {
    template <typename T>
    class function;

    template <typename Res, typename... Args>
    class function<Res(Args...)> {

    public:
        template <typename FunctionObject> requires std::is_invocable_v<FunctionObject, Args...>
        function(FunctionObject fo)
            : fun{new Derived<FunctionObject>(fo)}
        {}

        function() = default;
        
        function(const function& other) : fun{other.fun->get_copy()} {}
        
        function(function&& other) : fun{} {
            std::swap(fun, other.fun);
        }
        
        function& operator=(const function& rhs) {    
            //allocating memory
            auto tmp = rhs.fun->get_copy();
            if (fun != nullptr) fun->destroy();
            fun = tmp;
            return *this;
        }

        function& operator=(function&& rhs) {
            std::swap(fun, rhs.fun);
            return *this;
        }

        Res operator()(Args&&... args) {
            if (fun == nullptr) { abort(); }
            return (*fun)(std::forward<Args>(args)...); 
        }

        ~function() {
            if (fun != nullptr) fun->destroy();
            delete fun;
        };


    private:
        struct Base {
            virtual Res operator()(Args&&...) = 0;
            virtual Base* get_copy() = 0;
            virtual void destroy() = 0;
            virtual ~Base() = default;
        };

        template <typename F>
        struct Derived final : Base {
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
                callable.~F();

            }
            ~Derived() {}
        };

    private:
        Base* fun = nullptr;
    };
}