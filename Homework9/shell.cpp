#include "shell.hpp"
#include <iostream>

int sum(int x, int y) {
    return x + y;
}

auto lam = [](){ return 5; };


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

    shell<decltype(lam2(nullptr,nullptr))(int*,int*)> g2 {lam2, filename};
    int a, b;
    g2(&a, &b);

    return 0;
}