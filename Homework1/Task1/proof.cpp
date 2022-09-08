#include <iostream>

struct A {
    char b[3];
    char a;
    int d;
    double t;
};

struct B {
    char a;
    char b[3];
    int d;
    double t;
};

int main() {
    A a;
    std::cout << sizeof(a) << '\n';
    B b;
    std::cout << sizeof(b) << '\n';


}