#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <filesystem>
int main()
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-10000.0, 10000.0);
    std::vector<double> a(20000);
    
    for (auto& x : a) {
        x = dis(gen);
    }
    std::string in;
    std::cin >> in;
    std::fstream input{in, std::fstream::out | std::fstream::trunc};
    if (!input.good()) {
        std::cout << in;
        std::cout << "ERROR IN\n";
    }
    for(const auto x : a) {
        input << x << ' ';
    }

    std::sort(a.begin(), a.end());
    std::cin.clear();
    std::string sol;
    std::cin >> sol;
    std::fstream solution{sol, std::fstream::out | std::fstream::trunc};
    if (!solution.good()) {
        std::cout << sol;
        std::cout << "ERROR SOL\n";
    }
    for(const auto x : a) {
        solution << x << ' ';
    }
}
