#include <iostream>

struct Base {
    Base() { std::cout << "B\n"; };
    ~Base() {
        std::cout << "~B\n";
        abort();
    }
};

struct Derived : Base {
    int* ptr;
    Derived() : ptr(new int(100)) { std::cout << "D\n"; }
    ~Derived() {
        //this->Base::~Base(); //memleak if ~B before ~D
        std::cout << "~D\n";
        delete ptr;
    }
};

int main() {
    Derived d;
    return 0;
}