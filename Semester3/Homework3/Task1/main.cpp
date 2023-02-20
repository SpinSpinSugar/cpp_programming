#include "Task1.hpp"

int main() {
    auto a = quaternion<double> { 348029, -21804, 430298, 4213809 };
    auto b = quaternion<double> { -2315897, 432906, -52315, 1092 };
    auto p = a / b;
    auto ans = quaternion<double> { 0.1483, -0.0758, 0.5046, 1.7234 };
    std::cout << p << '\n' << ans;
    return 0;
}