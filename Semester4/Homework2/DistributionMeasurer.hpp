#ifndef DISTRIBUTION_MEASURER
#define DISTRIBUTION_MEASURER 1

#include <chrono>
#include <thread>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include "ThreadsafeQueue.hpp"

namespace threadPerf
{

    struct Task {
        using Time = std::chrono::microseconds;
        Time creationTime;
        Time runTime;

        Task(unsigned int creation, unsigned int run): Task{std::chrono::microseconds(creation), std::chrono::microseconds(run)} {}

        Task(Time creation, Time run): creationTime{creation}, runTime{run} {
            std::this_thread::sleep_for(creationTime);
        }

        void operator()() {
            std::this_thread::sleep_for(runTime);
        }

        Task(const Task& t) = default;
        Task(Task&& t) = default;
        Task& operator=(const Task& rhs) = default;
        Task& operator=(Task&& rhs) = default;
        ~Task() {
            //std::cout << "done\n";
        };
    };

    void runTasks(unsigned int numberOfTasks, unsigned int generationTime, unsigned int runTime, unsigned int numberOfGenerators, unsigned int numberOfWorkers) {
        threadsafe_queue<Task> queue;
        std::vector<std::jthread> generators;
        generators.reserve(numberOfGenerators);
        std::vector<std::jthread> workers;
        workers.reserve(numberOfWorkers);
        const std::atomic<unsigned int> maxNumber = numberOfTasks;
        std::atomic<unsigned int> counter = 0;

        for (int i = 0; i < numberOfGenerators; ++i) {
            generators.emplace_back([&]() {
                    while (counter < maxNumber) {
                        queue.push({generationTime, runTime});
                        ++counter;
                    }
                });
        }

        std::atomic<int> counter2 = numberOfTasks;
        for (int i = 0; i < numberOfWorkers; ++i) {
            workers.emplace_back([&]() {
                    while (counter2 > 0) {
                        auto task = queue.try_pop();
                        if (static_cast<bool>(task) != 0) (*task)();
                        --counter2;
                    }
                });
        }
    }

    struct Measurment {
        std::chrono::nanoseconds time;
        int numberOfGenerators;
        int numberOfWorkers;
    };

    auto measureDistribution(unsigned int numberOfTasks, unsigned int generationTime, unsigned int runTime) {
        std::vector<Measurment> result;
        result.reserve(std::thread::hardware_concurrency());
        for (int i = 1; i < std::thread::hardware_concurrency() - 1; ++i)
        {
            int numberOfGenerators = i;
            int numberOfWorkers = std::thread::hardware_concurrency() - i - 1;
            auto start = std::chrono::high_resolution_clock::now();

            runTasks(numberOfTasks, generationTime, runTime, numberOfGenerators, numberOfWorkers);

            auto end = std::chrono::high_resolution_clock::now();
            result.push_back({end - start, numberOfGenerators, numberOfWorkers});
        }
        return *std::min_element(result.begin(), result.end(), [](auto rhs, auto lhs) { return rhs.time < lhs.time; });
    }
}

#endif
