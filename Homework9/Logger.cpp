#include <iostream>
#include "Logger.hpp"

int foo(int,int) { return 0; }

int main() {
    shell<int(int,int)> s = foo;
}