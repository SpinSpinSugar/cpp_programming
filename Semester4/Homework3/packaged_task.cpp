#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <utility>
#include <exception>
#include <gtest/gtest.h>

auto task_package(int sz) {
    if (sz < 0) throw std::runtime_error{"Negative size of vector"};
    std::packaged_task generate_data { [size = std::as_const(sz)] () {
        std::vector<int> data;
        data.reserve(size);
        std::generate_n(std::back_inserter(data), size, [i = size] () mutable { return --i; });
        return data;
    }};

    std::future generated_data = generate_data.get_future();

    std::packaged_task shuffle_data { [generated_data = std::move(generated_data)] () mutable {
        std::random_device d;
        std::mt19937 gen(d());
        auto data = generated_data.get();
        std::shuffle(data.begin(), data.end(), gen);
        return data;
    }};

    std::future shuffled_data = shuffle_data.get_future();

    std::packaged_task sort_data {
        [shuffled_data =std::move(shuffled_data)] () mutable {
            auto data = shuffled_data.get();
            std::sort(data.begin(), data.end());
            return data;
        }
    };

    std::future sorted_data = sort_data.get_future();

    std::jthread t1 {std::move(generate_data)};
    std::jthread t2 {std::move(shuffle_data)};
    std::jthread t3 {std::move(sort_data)};

    
    return sorted_data.get() ;
}

TEST(ASSERT_CHECK, N10000000) {
    auto res = task_package(10000000);
    int i = 0;
    for (const auto x : res) {
        ASSERT_EQ(x, i);
        ++i;
    }
}

TEST(ASSERT_CHECK, N0) {
    auto res = task_package(0);
    int i = 0;
    for (const auto x : res) {
        ASSERT_EQ(x, i);
        ++i;
    }
}

TEST(ASSERT_CHECK, Negative) {
    ASSERT_THROW(auto res = task_package(-10000000), std::runtime_error);
    
}