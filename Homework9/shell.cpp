#include "shell.hpp"
#include <iostream>
#include <functional>

int sum(int x, int y) {
    return x + y;
}

struct Callabl {
    int operator()() { return 5;}
};

struct StructWithFunct {
    int a = 999;
    int f() { return a; }
};



int main() {
    std::string filename = "CallHistory.log";
    
    shell<int(int,int)> first;
    shell<int(int,int)> third;
    auto lambd = [](){ return 100; };

    //copy and move assigment + dtor correctness
    {
        shell<int(int,int)> second{sum, filename};
        second(2, -10);
        second(152, 253);
        first = second;
        third = std::move(second);
    }
    
    //movable
    third(203, 12035);

    //move ctor;
    shell<int()> tmp = [](){ return 42;};
    auto real {std::move(tmp)};

    // call after move - UB
    //tmp();

    //copyable
    shell<int(int,int)> real2{sum};
    
    auto newReal {real2};
    newReal(12, 15);
    
    //call after copy
    real2(12, 15);

    
    //lambda is working
    shell<int()> g{lambd, filename};
    g();
    
    auto lam2 = [](int* a, int* b){ return a - b; };
    shell<decltype(lam2(nullptr, nullptr))(int*, int*)> g2 {lam2, filename};
    int a, b;
    g2(&a, &b);
    
    //functor
    Callabl c;
    shell<int()> c_wrapper {c, filename};
    c_wrapper();

    // ptr to member function
    StructWithFunct s;
    shell<int()> s_wrapper = std::bind(&StructWithFunct::f, &s); // WOW!
    s_wrapper.change_filename(filename);
    std::cout << s_wrapper() << '\n';
}