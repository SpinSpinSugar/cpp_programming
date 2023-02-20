#include "MutexWrapper.hpp"
#include <iostream>
#include <thread>

cl#include <format>

void test() {
    std::cout << "VOID\n";
};

int b() {
    std::cout << "INT\n";
    return 1;
}

std::mutex mtx;

int main() {
    FunctorGuard a {b};
    FunctorGuard t2 {test};
    t2();
    std::function tmp {b};
    std::thread tr1(std::ref(a));

    tr1.join();
}