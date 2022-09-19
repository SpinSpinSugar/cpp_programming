#include "Task1_n.hpp"

int main() {
    MyArray test0;
    MyArray test1(0);
    MyArray test2(5);
    for (int i = 0; i < test2.size(); ++i) {
        test2[i] = i;
    }
    test2.print();
    MyArray test3(test2);
    test3.print();
    test1 = std::move(test2);
    test1.print();
    std::cout << test2.size() << '\n';
    std::cout << test3.size() << '\n';
    std::cout << test2.size() << '\n';
    MyArray b{};
    MyArray a(std::move(b));
    return 0;
}