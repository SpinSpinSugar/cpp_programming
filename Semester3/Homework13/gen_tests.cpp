#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <thread>

void task1(const std::string& in, std::vector<double>& a) {
    std::fstream input{in, std::fstream::out | std::fstream::trunc};
    if (!input.good()) {
        std::cout << in;
        std::cout << "ERROR IN\n";
    }
    for(const auto x : a) {
        input << x << ' ';
    }
}

void task2(const std::string& sol, std::vector<double>& a) {
    std::sort(a.begin(), a.end());
    std::fstream solution{sol, std::fstream::out | std::fstream::trunc};
    if (!solution.good()) {
        std::cout << sol;
        std::cout << "ERROR SOL\n";
    }
    for(const auto x : a) {
        solution << x << ' ';
    }

}

int main()
{
    std::vector<double> a(10000000);
    std::string in = "test1.txt";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-100000, 100000);
    for (auto& x : a) {
        x = dis(gen);
    }
#ifdef NPAR
    task1(in, a);
#endif
#ifndef NPAR
    std::thread t1(task1, std::ref(in), std::ref(a));
#endif
    std::vector second = a;


    std::string ans = "ans1.txt";
#ifdef NPAR
    task2(ans, second);
#endif
#ifndef NPAR
    std::thread t2(task2, std::ref(ans), std::ref(second));
    t1.join();
    t2.join();
#endif
}
