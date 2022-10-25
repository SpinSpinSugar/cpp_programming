#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path WorkingPath;
    try {
        WorkingPath = fs::current_path(); //can throw fs::filesystem_error
    } catch (const fs::filesystem_error&) {
        std::cout << "Whoops, bad path. Aborting...\n";
        abort();
    }
    
    double Numerator;
    std::cout << "Input the filename of numerator file:\n";
    std::string NumFileName;
    std::ifstream NumFile; //Create stream to read from file
    try {
        std::cin >> NumFileName;
        WorkingPath /= NumFileName;
        NumFile.open(WorkingPath);
        if (!NumFile.good()) NumFile.exceptions(NumFile.failbit);
        NumFile >> Numerator;
    } catch (const std::ios_base::failure& exc) {
        std::cout << "Bad name of Numerator file. Input correct one:\n";
        std::cin >> NumFileName;
        WorkingPath.replace_filename(NumFileName);
        //std::cout << WorkingPath.string();
        NumFile.clear();
        NumFile.open(WorkingPath);
        NumFile >> Numerator;
    }


    double Denominator; 
    std::cout << "Input the Denominator:\n";
    std::string DenStr;
    std::cin >> DenStr;
    try {
        Denominator = std::stod(DenStr);
    } catch (const std::out_of_range& exc) {
        std::cout << "Hey bro, this number too big for double, change it:\n";
        std::cin >> DenStr;
        Denominator = std::stod(DenStr);
    } catch (const std::invalid_argument& exc) {
        std::cout << "This Denominator is not a double number, change it:\n";
        std::cin >> DenStr;
        Denominator = std::stod(DenStr);
    }


    std::cout << Numerator << ' ' << Denominator << '\n';

    std::cout << "Input the filename of output file:\n";
    std::string OutFileName;
    std::cin >> OutFileName;
    WorkingPath.replace_filename(OutFileName);
    std::ofstream OutFile(WorkingPath);
    try {
        if (Denominator == 0 && Numerator == 0) throw std::runtime_error("Undefined result");
        if (Denominator == +0.0 && Numerator > 0) throw std::overflow_error("Division by zero, +inf");
        if (Denominator == -0.0 && Numerator > 0) throw std::underflow_error("Division by zero, -inf");
        if (Denominator == +0.0 && Numerator < 0) throw std::underflow_error("Division by zero, -inf");
        if (Denominator == -0.0 && Numerator < 0) throw std::overflow_error("Division by zero, +inf");
        OutFile << Numerator / Denominator;
    } catch (const std::runtime_error& exc) {
        if (typeid(std::overflow_error) == typeid(exc)) {
            OutFile << "+inf";
        }
        if (typeid(std::underflow_error) == typeid(exc)) {
            OutFile << "-inf";
        }
        if (typeid(std::underflow_error) == typeid(exc)) {
            OutFile << "-inf";
        }
        if (typeid(std::runtime_error) == typeid(exc)) {
            OutFile << "error";
        }
    }
    std::cout << "Result: " <<Numerator / Denominator << '\n';
    return 0;
}