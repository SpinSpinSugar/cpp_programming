#include <iostream>
#include "DistributionMeasurer.hpp"

int main(int argc, const char* argv[]) {
    //Preparation
    if (argc > 1 && std::string{argv[1]} == "-h") {
        std::cout << "no params: minimal measurment\n"
            << "-h: for help\n"
            << "-a: for all measurments\n";
        return 0;
    }

    std::cout << "Input number of tasks: ";
    unsigned int numberOfTasks;
    std::cin >> numberOfTasks;

    unsigned int genTime;
    std::cout << "Input generation time: ";
    std::cin >> genTime;

    unsigned int compTime;
    std::cout << "Input computation time: ";
    std::cin >> compTime;

    //Measuring distribution
    auto ans = threadPerf::measureDistribution(numberOfTasks, genTime, compTime);

    if (argc > 1 && std::string{argv[1]} == "-a") {
        std::cout << '\n';
        ans.print();
    }

    auto result = ans.get_min_element();
    std::cout << "\nBest configuration:\n"
        << "Generators: " << result.numberOfConsumers
        << "\nWorkers: " << result.numberOfProducers
        << "\nTime: " << result.count() << " microseconds" << '\n';
}
