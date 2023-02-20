#include <iostream>

class Big {
    char c[3] = {0xA, 0xB, 0xC};
    unsigned long long d = 0xD;
    float g = 0;
    float* h;
    int b = 0xE;
    int* a;
    double f = 0xFFFFFFFF;
    char e = 0xD;
};

class Small {
    char c[3] = {0xA, 0xB, 0xC};
    char e = 0xD;
    int b = 0xE;
    float g = 0;
    double f = 0xFFFFFFFF;
    float* h;
    int* a;
    unsigned long long d = 0xD;
};

int main() {
    Big big;
    Small small;
    std::cout << sizeof(big) << ' ' << sizeof(small);
    return 0;
}