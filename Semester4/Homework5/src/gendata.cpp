#include <iostream>
#include <fstream>
#include <random>
#include <utility>
#include <limits>
#include <vector>
#include <cmath>

inline constexpr int NUMBER_OF_DATA_CLASSES = 6;
inline constexpr int NUMBER_OF_DOTS = 100'000;

void gendata(std::fstream& outputFile) {
    outputFile << NUMBER_OF_DOTS << '\n';
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_real_distribution<float> distr{-1.0, 1.0};

    std::vector<int> data_classes;
    data_classes.reserve(NUMBER_OF_DOTS);

    std::vector<float> x_coords;
    x_coords.reserve(NUMBER_OF_DOTS);

    std::vector<float> y_coords;
    y_coords.reserve(NUMBER_OF_DOTS);

    for (int i = 0; i < NUMBER_OF_DOTS; ++i) {
        int n = gen() % NUMBER_OF_DATA_CLASSES;
        data_classes.push_back(n);
        std::pair point = { 0.0f, 0.0f };
        switch (n) {
        case 0:
            //Fig. 0 is circle with R = 50000 and center(100000, 50000)
        {
            constexpr long long R = 500000;
            float x, y;
            for (;;) {
                point.first = 1000000 + distr(gen) * R;
                point.second = 500000 + distr(gen) * R;
                x = point.first - 1000000;
                y = point.second - 500000;
                if (x * x + y * y <= R * R) break;
            }
        }
        break;
        case 1:
            //Fig. 1 is rectangle [1500000, 3000000] x [0, 3500000]
        {
            constexpr long long R = 1750000;
            point.first = std::abs(distr(gen)) * R + 1750000;
            point.second = std::abs(distr(gen)) * R * 2;
        }
        break;
        case 2:
            //Fig. 2 is circle = (1000000, 2500000), R = 400000
        {
            constexpr long long R = 1300000;
            float x, y;
            for (;;) {
                point.first = 500000 + distr(gen) * R;
                point.second = 2500000 + distr(gen) * R;
                x = point.first - 500000;
                y = point.second - 2500000;
                if (x * x + y * y <= R * R) break;
            }
        }
        break;
        case 3:
            //Fig. 3 is rectangle = [-1000000, 1000000] x [-10000, 0], R = 400000
        {
            constexpr long long R = 1000000;
            point.first = distr(gen) * R;
            point.second = -std::abs(distr(gen) * R) * 3;
        }
        break;
        case 4:
        {
            //Fig. 4 is circle = (2500000, -1600000), R = 400000
            constexpr long long R = 1600000;
            float x, y;
            for (;;) {
                point.first = 2500000 + distr(gen) * R;
                point.second = -1600000 + distr(gen) * R;
                x = point.first - 2500000;
                y = point.second + 1600000;
                if (x * x + y * y <= R * R) break;
            }
            break;
        }
        case 5:
        {
            //Fig. 5 is circle = (2500000, -1600000), R = 400000
            constexpr long long R = 1600000;
            float x, y;
            for (;;) {
                point.first = -2500000 + distr(gen) * R;
                point.second = 1600000 + distr(gen) * R;
                x = point.first + 2500000;
                y = point.second - 1600000;
                if (x * x + y * y <= R * R) break;
            }
            break;
        }
        break;
        default:
            std::unreachable();
        }
        x_coords.push_back(point.first);
        y_coords.push_back(point.second);
    }

    for (const auto n : data_classes) {
        outputFile << n << ' ';
    }

    outputFile << '\n';

    for (const auto x : x_coords) {
        outputFile << x << ' ';
    }

    outputFile << '\n';

    for (const auto y : y_coords) {
        outputFile << y << ' ';
    }
    outputFile << '\n';
}

int main() {
    std::fstream outputFile{"../data/dataset", std::fstream::out};
    gendata(outputFile);
}