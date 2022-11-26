#include <iostream>
#include <fstream>
#include <vector>

// stupidest way

struct Dictionary_Unit {
    std::string American;
    std::string Indian;
    Dictionary_Unit(std::string f, std::string s) : American(f), Indian(s) {}
};

int main() {
    std::string filename = "Dictionary.txt";
    std::cout << "Input filename of dictionary:\n";
    //std::cin >> filename;
    std::fstream file {filename, file.in};
    std::vector<Dictionary_Unit> dictionary;
    for(;;) {
        std::string key, value;
        file >> key >> value;
        dictionary.emplace_back(key, value);
        if (file.eof()) break;
    }
    for(;;) {
        std::cout << "0. Exit\n";
        std::cout << "1. Print dictionary\n";
        std::cout << "2. Find word, that starts with this symbol\n";
        std::cout << "3. Find whole word\n";
        std::cout << "4. Translate word\n";
        int value;
        std::cin >> value;
        switch (value)
        {
        case 0:
            return 0;
            break;
        case 1:
            system("clear");
            for (const auto& [american, indian] : dictionary) {
                std::cout << "American: " << american << " Indian: " << indian << '\n';
            }
            break;
        
        case 2:
            system("clear");
            std::cout << "Input first letter:\n";
            char firstLetter;
            std::cin >> firstLetter;
            for (const auto& [american, indian] : dictionary) {
                if (american[0] == firstLetter) std::cout << "American: " << american << '\n';
                if (indian[0] == firstLetter) std::cout << "Indian: " <<  indian  << '\n';
            }
            std::cout << '\n';
            break;
        case 3:
            system("clear");
            std::cout << "Input word:\n";
            char word[20];
            std::cin >> word;
            for (const auto& [american, indian] : dictionary) {
                if (american == word) std::cout << "American: " << american << '\n';
                if (indian == word) std::cout << "Indian: " << indian  << '\n';
            }
            std::cout << '\n';
            break;

        case 4:
            system("clear");
            std::cout << "Input word:\n";
            char word2[20];
            std::cin >> word2;
            for (const auto& [american, indian] : dictionary) {
                if (american == word2) std::cout << "American: " << american << " Indian: " << indian << '\n';
                if (indian == word2) std::cout << "Indian: " << indian << " American: " << american << '\n';
            }
            std::cout << '\n';
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        } 
    }
}