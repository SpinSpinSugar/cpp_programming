#include <iostream>

struct S {
    S() = default;
    S(const S& rhs) {
        *this = rhs;
        std::cout << "Copy\n";
    }
};

S foo(S s, int n) {
    if (n > 0) return foo(s, n / 4);
    return s;
}

int main() {
    S s;
    foo(s, 11);
    return 0;
}