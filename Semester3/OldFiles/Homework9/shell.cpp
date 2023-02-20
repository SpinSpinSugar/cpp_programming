#include "shell.hpp"
#include <iostream>
#include <functional>

int sum(int x, int y) {
    return x + y;
}

auto lam = [](){ return 5; };

struct C {
    int call(int a) { return a; } 
};

int main() {
    auto lam2 = [=](int* a, int* b) { return a - b; };
    std::string filename = "log.txt";
    //std::fstream output {filename, output.out};
    shell<int(int,int)> f{sum, filename};
    f(1,2);
    f(2, -10);
    //std::fstream output2 {"log2.txt", output2.out};
    shell<int()> g{lam, filename};
    g();

    shell<decltype(lam2(nullptr, nullptr))(int*, int*)> g2 {lam2, filename};
    int a, b;
    g2(&a, &b);

    shell<int(int,int)> copy {std::move(f)};


    //shell<int(int)> xx {p, filename};

#ifndef SEGFAULT
    //f(2, -10);
#endif
    copy(2, -10);
    return 0;
}