#include <iostream>
#include <fstream>
#include <filesystem>
#include <limits>

namespace fs = std::filesystem;

int main() {
    fs::path WorkingPath = fs::current_path();
    
    double Numerator;
    std::cout << "Input the filename of numerator file:\n";
    std::string NumFileName;
    std::ifstream NumFile; //Create stream to read from file
    std::cin >> NumFileName;
    WorkingPath /= NumFileName;
    NumFile.open(WorkingPath);
    NumFile >> Numerator;

    double Denominator; 
    std::cout << "Input the Denumerator:\n";
    std::string DenStr;
    std::cin >> DenStr;
    Denominator = std::stod(DenStr);

    std::cout << Numerator << ' ' << Denominator << '\n';

    std::cout << "Input the filename of output file:\n";
    std::string OutFileName;
    std::cin >> OutFileName;
    WorkingPath.replace_filename(OutFileName);
    std::ofstream OutFile(WorkingPath);
    OutFile << Numerator / Denominator;
    std::cout << "Result: " << Numerator / Denominator << '\n';
    return 0;
}