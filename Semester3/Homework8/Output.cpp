#include "myVector.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    myVector<int> Vector = {1, 2, 4, 5, -2135, 34634};
    std::filebuf FileBuf;
    std::cout << "Choose file to save your vector:\n";
    std::string Filename;
    std::cin >> Filename;
    dump_myVector(Vector, Filename);
    return 0;
}