//#include <iostream>
#include "myVector.hpp"

int main() {
    myVector<int> a;
    for (int i = 0; i < 33; ++i) {
        a.push_back(i);
        //std::cout << a.size() << ' ' << a.capacity() << '\n';
    }
    myVector<int> b(a);
    b.push_back(25);
    //std::cout << b;
    //myVector<myVector<int>> c(1, a);
    //std::cout << sizeof(size_t) << '\n';
    //std::cout << std::hex << std::numeric_limits<size_t>::max() << '\n';
    return 0;
}