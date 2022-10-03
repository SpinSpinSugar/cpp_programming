#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
 
int main()
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-100.0, 100.0);
    std::vector<double> a(15);
    for (auto& x : a) {
        x = dis(gen);
        std::cout << x << ", ";
    }
    std::cout << '\n';
    auto b = a;
    std::sort(b.begin(), b.end());
    for (auto& x : b) {
        std::cout << x << ", ";
    }
    std::cout << '\n';
}