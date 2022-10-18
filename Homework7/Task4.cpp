#include <iostream>

template <typename T, int n>
struct myArray{
    myArray() {std::cout << "generic type\n"; }
};
template <typename T>

struct myArray<T, 1> {
    myArray() {std::cout << "partial spec\n"; }
};
int main() {
    myArray<float, 0> a;
    myArray<float, 1> c;
    return 0;
}