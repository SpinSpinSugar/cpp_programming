#include "myVector.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::cout << "Choose file of vector:\n";
    std::string Filename;
    std::cin >> Filename;

    myVector<int> TEST = input_myVector<int>(Filename);
    std::cout << "myVector<int> " << TEST.size() << ' ' << TEST.capacity() << ' ';
    for (int i = 0; i < TEST.size(); ++i) {
        std::cout << TEST[i] << ' ';
    }
    
    return 0;
}