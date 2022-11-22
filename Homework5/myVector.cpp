#include <iostream>
#include "myVector.hpp"

int main() {
    myVector<int> b;
    std::cout << b.size() << ' ' << b.capacity() << '\n';
    for (int i = 0; i < 33; ++i) {
        b.push_back(i);
        std::cout << b.size() << ' ' << b.capacity() << '\n';
    }
    b.pop_back();
    std::cout << '\n';
    
    myVector<std::string> a;
    a.push_back("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    
    myVector<myVector<int>> c = {{1}, {2}, {3}, {4}, {5}, {6}};
    std::cout << c.size() << ' ' << c.capacity() << '\n';
    c.pop_back();
    std::cout << c.size() << ' ' << c.capacity() << '\n';
    c.resize(2);
    std::cout << c.size() << ' ' << c.capacity() << '\n';

    myVector<int> test {1, 2, 3, 4, 5};
    b = test;

    return 0;
}