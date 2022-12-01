#include "myfunction.hpp"
#include <fstream>
#include <chrono>

namespace details {
    static unsigned long long COUNTER = 0;
}

template <typename Res, typename... Args>
class shell final {
    my::function<Res(Args...)> fun;
    mutable std::string filename;
    Res operator()(Args&&... args) {
        fun(std::forward(args)...);
        if (fun == nullptr) { abort(); }
        Res res = (*fun)(std::forward<Args>(args)...); 
        std::fstream outfile{filename, outfile.out | std::ios::app};
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        outfile << ctime(&t) << ' ';
        outfile << details::COUNTER << ". Function " << typeid(*this).name() << " called with arguments: (";
        print_args(outfile, args...);
        outfile << ')' << " Result: " << res << '\n';
        return res;
    }

private:
    void print_args([[maybe_unused]] std::fstream& outfile) {}

    template <typename T> void print_args(std::fstream& outfile, T&& t) {
        outfile << std::forward<T>(t);
    }
    
    template <typename First, typename... Rest>
    void print_args(std::fstream& outfile, First&& first, Rest&&... rest) {
        outfile << std::forward<First>(first) << ", ";
        print_args(outfile, rest...); 
    }

public:
    void change_filename(const std::string& newfilename) const {
        filename = newfilename;
    }
};