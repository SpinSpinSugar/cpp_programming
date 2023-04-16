#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include "BlockingStack.hpp"
#include "LockfreeStack.hpp"
#include <vector>

/*
* Input:
* 1 - number of tasks, 2 - number of producers, 3 - number of consumers
* Output:
* Time of blocking stack, time of lockfree stack
*
*/

std::atomic<int> numberOfTasks;

void produce(auto& stack) {
    for (;;) {
        int n = numberOfTasks.load();
        if (n < 0)
            break;
        while(!numberOfTasks.compare_exchange_weak(n, n-1, std::memory_order_relaxed)) {
            if (n < 0) return;
            std::this_thread::yield();
        }
        stack.push(std::move(n));        
    }
}
std::atomic<int> sum = 0;
void consume(auto& stack) {
    for (;;) {
        int n = numberOfTasks.load();
        if (n < 0 && stack.empty())
            break;
        auto val = stack.pop();
        if (val) sum += *val;
  }
}

int main(int argc, char* argv[]) {
    
    if (argc != 4) {
        std::cerr << "Incorrect arguments\n";
        return 1;
    }
    const int NTASKS_KEEPER = std::atoi(argv[1]); 
    const int numberOfProducers = std::atoi(argv[2]);
    const int numberOfConsumers = std::atoi(argv[3]);
    numberOfTasks = NTASKS_KEEPER;

    if (numberOfTasks < 0 || numberOfConsumers < 1 || numberOfProducers < 1) {
        throw std::runtime_error{"Incorrect arguments\n"};
    }

    const auto startBlockingStack = std::chrono::high_resolution_clock::now();
    {
        threadPerf::BlockingStack<int> blockingStack {};
        std::vector<std::jthread> producers;
        std::vector<std::jthread> consumers;
        for (int i = 0; i < numberOfProducers; ++i) 
            producers.emplace_back(produce<threadPerf::BlockingStack<int>>, std::ref(blockingStack));
        for (int i = 0; i < numberOfProducers; ++i) 
            consumers.emplace_back(consume<threadPerf::BlockingStack<int>>, std::ref(blockingStack));
    }
    auto blockingSum = sum.load();
    sum = 0;
    numberOfTasks = NTASKS_KEEPER;

    const auto endBlockingStack = std::chrono::high_resolution_clock::now();
    const auto timeBlocking = endBlockingStack - startBlockingStack;
    const auto startLockfreeStack = std::chrono::high_resolution_clock::now();
    {
        threadPerf::LockfreeStack<int> lockfreeStack{};
        std::vector<std::jthread> producers;
        std::vector<std::jthread> consumers;
        for (int i = 0; i < numberOfProducers; ++i) 
            producers.emplace_back(produce<threadPerf::LockfreeStack<int>>, std::ref(lockfreeStack));
        for (int i = 0; i < numberOfProducers; ++i) 
            consumers.emplace_back(consume<threadPerf::LockfreeStack<int>>, std::ref(lockfreeStack));
    }
    const auto endLockfreeStack = std::chrono::high_resolution_clock::now();
    const auto timeLockfree = endLockfreeStack - startLockfreeStack;
    auto lockfreeSum = sum.load();
    std::cout << "Blocking stack: " << std::chrono::duration_cast<std::chrono::microseconds>(timeBlocking) << '\n'
              << "Lockfree stack: " << std::chrono::duration_cast<std::chrono::microseconds>(timeLockfree) << '\n'
              << blockingSum  << ' ' << lockfreeSum << '\n';
}
