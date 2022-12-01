#include "generic_sort.h"
#include <iostream>
#include <fstream>
#include <vector>

int VAL = 1500000;
int main() {
    std::string in;
    std::cin >> in;
    std::fstream input{in, std::fstream::in};
    std::vector<double> a;
    a.resize(20000);
    for (auto& x : a) {
        input >> x;
    }

    generic_sort(&a[0], 20000, sizeof(double), generic_sort_utility::less_double, generic_sort_utility::bubble_sort);
    std::string out;
    std::cin >> out;
    std::fstream output{out, std::fstream::out | std::fstream::trunc};
    for (const auto x : a) {
        output << x << ' ';
    }
}
//-2 0