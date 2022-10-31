#include "myVector.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

struct A {
    int a;
    double b;
};

std::ostream& operator<<(std::ostream& os, const A& tmp) {
    os << "INT: " << tmp.a << ' ' << "DOUBLE: " << tmp.b << '\n';
    return os;
}

int main() {
    myVector<A> Vector = {{1, 0.5}, {1235, 34.35}, {-1246, 595677543215123}};
    std::filebuf FileBuf;
    std::cout << "Choose file to save your vector:\n";
    std::string Filename = "test";
    dump_myVector(Vector, Filename);
    myVector<A> newVector = input_myVector<A>(Filename);
    for (int i = 0; i < newVector.size(); ++i) {
        std::cout << newVector[i];
    }
    return 0;
}