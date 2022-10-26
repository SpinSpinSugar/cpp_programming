#include <iostream>

template <typename T, typename N>
struct myArray {
    myArray() {std::cout << "generic type\n"; }
};
template <typename T>

struct myArray<T, int> {
    myArray() {std::cout << "partial spec\n"; }
};
int main() {
    myArray<float, int*> a;
    myArray<float, int> c;
    return 0;
}