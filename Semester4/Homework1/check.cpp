#include <iostream>
#include <thread>
#include "MutexWrapper.hpp"

//#include <format>

void test() {
    std::cout << "VOID\n";
}

int b() {
    std::cout << "INT\n";
    return 1;
}

std::mutex mtx;

int main() {
    FunctorGuard a {b};
    FunctorGuard t2 {test};
    std::function tmp {b};
    std::thread tr1(std::ref(a));
    std::thread tr2(std::ref(t2));
    tr1.join();
    tr2.join();
}
