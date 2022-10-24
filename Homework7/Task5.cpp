#include <iostream>
#include <stdexcept>

struct A {
    A& operator=(int rhs) { throw std::runtime_error{"A op="}; }
    bool operator<(int rhs) { throw std::runtime_error{"A op<"}; }
    void operator++(int) { throw std::runtime_error{"A op++(int)"}; }
} a;


struct C {
    int operator+=(A& rhs) { throw std::runtime_error{"C op+="}; return 1; }
} c;

    bool operator==(int lhs, C& rhs) { throw std::runtime_error{"C op=="}; return rand() % 2 ? 0 : 1; }

struct B {
    B operator++() { throw std::runtime_error{"B op++(int)"}; return *this; }
    int operator+(A& rhs) { throw std::runtime_error{"B op+(int)"}; return 2; }
} b;

B foo() {
    cycle:
    try {
        for (a = 42; a < 146; a++) {
            if (++b + a == c) return b;
            c += a;
        }
    } catch(const std::exception& exc) {
        std::cout << exc.what();
    }
    //goto cycle;
}

int main() {
    foo();
}