#include <iostream>

class A {
    int x = 0xA;
    char y = 0xB;
    double z = 0xFFFFp0;
    void print_x();
    void print_y();
    void print_z();
};
// TODO function call
void A::print_x() { std::cout << x << '\n'; }
void A::print_y() { std::cout << y << '\n'; }
void A::print_z() { std::cout << z << '\n'; }

int main() {
    A obj;

    int* addr_of_x = reinterpret_cast<int*>(&obj);
    std::cout << "Initialized x = " << std::hex << *addr_of_x << '\n';
    *addr_of_x = 0xBEEF;
    std::cout << "Changed x = " << std::hex << *addr_of_x << '\n';
    
    int* addr_of_y = reinterpret_cast<int*>(&obj);
    ++addr_of_y;
    std::cout << "Initialized y = " << std::hex << *addr_of_y << '\n';
    *addr_of_y = 0xC;
    std::cout << "Changed y = " << std::hex << *addr_of_y << '\n';

    double* addr_of_z = reinterpret_cast<double*>(&obj);
    ++addr_of_z;
    std::cout << "Initialized z = " << std::hexfloat << *addr_of_z << '\n';
    *addr_of_z = 0xAAAAp0;
    std::cout << "Changed z = " << std::hexfloat << *addr_of_z << '\n';

    return 0;
}