#include <iostream>
#include "DistributionMeasurer.hpp"

int main() {
    std::cout << "Input number of tasks: ";

    unsigned int numberOfTasks;
    std::cin >> numberOfTasks;

    unsigned int genTime;
    std::cout << "\nInput generation time: ";
    std::cin >> genTime;

    unsigned int compTime;
    std::cout << "\nInput computation time: ";
    std::cin >> compTime;

    auto result = threadPerf::measureDistribution(numberOfTasks, genTime, compTime);
    std::cout << "Best configuration:\n" << "Generators: " << result.numberOfGenerators
              << "\nWorkers: " << result.numberOfWorkers
              << "\nTime: " << std::chrono::duration_cast<std::chrono::microseconds>(result.time).count() << " microseconds" << '\n';

}
