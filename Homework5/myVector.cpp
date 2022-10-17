#include <iostream>
#include "myVector.hpp"

int main() {
    myVector<std::string> a;
    a.push_back("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    myVector<int> b;
    for (int i = 0; i < 10000; ++i) {
        b.push_back(i);
    }
    myVector<myVector<int>> c = {{1}, {2}, {3}, {4}}; 
    
    return 0;
}