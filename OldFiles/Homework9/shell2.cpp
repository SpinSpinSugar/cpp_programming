#include "shell2.hpp"
#include <iostream>
#include <functional>

int sum(int x, int y) {
    return x + y;
}

auto lambd = [](){ return 100; };

auto lam2 = [](int* a, int* b){ return a - b; };

int main() {
    std::string filename = "log2.txt";
    
    shell<int(int,int)> first;
    shell<int(int,int)> third;
    {
        shell<int(int,int)> second{sum, filename};
        second(2, -10);
        second(152, 253);
        first = second;
        third = std::move(second);
    }
    shell<int()> g{lambd, filename};
    g();
    first(12, 15);

#if 1
    shell<decltype(lam2(nullptr, nullptr))(int*, int*)> g2 {lam2, filename};
    int a, b;
    g2(&a, &b);
#endif
    return 0;
}