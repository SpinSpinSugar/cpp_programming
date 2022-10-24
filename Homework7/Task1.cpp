#include <iostream>

static int i = 0;
struct S {
    int k = i;
    S() { std::cout << "Ctor s" << k << '\n'; ++i; }
    ~S() { std::cout << "Dtor s" << k << '\n';}
};

S s0; //global var

struct Wrapper {
    S s;
    ~Wrapper() {};
};

struct Wrapper2 {
    S* arr = new S[1];
    ~Wrapper2() { delete[] arr; }
};

static S s1; //static var
int main() {
    S s2; // lifetime ends
    try {
        S s3;
        std::cout << "Stack unwinding: "; 
        throw std::bad_alloc();
    } catch (std::bad_alloc& ) { }
    Wrapper s4; //Dtor calls dtors of field
    Wrapper2 s5; //delete calls destructors after new
    return 0;
}
