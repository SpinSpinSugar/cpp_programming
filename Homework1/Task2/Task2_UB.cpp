//  ##   ##  ######  
//  ##   ##  ##   ## 
//  ##   ##  ##   ## 
//  ##   ##  ######  
//  ##   ##  ##   ## 
//  ##   ##  ##   ## 
//   #####   ###### 
// В данной программе reinterpet_cast, std::memcpy или std::bitcast == UB из-за Strict Aliasing Violation [basic.lval//11].
// Strict Aliasing Violation: l-value не может быть адресовано указателями двух разных типов, за исключением тривиальных случаев, типа char*, ... ( не наш вариант) 
// Из-за этого UB менялся sizeof(obj) во время выполнения программы :))))

#include <iostream>

class A {
    int x = 0xA;
    char y = 'B';
    double z = 0xFFFFp0;
    void print_x();
    void print_y();
    void print_z();
};
void A::print_x() { std::cout << "x = " << x << '\n'; }
void A::print_y() { std::cout << "y = " << y << '\n'; }
void A::print_z() { std::cout << "z = " << z << '\n'; }

int main() {
    A obj;

    int* addr_of_x = reinterpret_cast<int*>(&obj);
    std::cout << "Initialized x = " << std::hex << *addr_of_x << '\n';
    *addr_of_x = 0xBEEF;
    std::cout << "Changed x = " << std::hex << *addr_of_x << '\n';
    
    int* addr_of_y = reinterpret_cast<int*>(&obj);
    ++addr_of_y;
    std::cout << "Initialized y = " << std::hex << *addr_of_y << '\n';
    *addr_of_y = 'C';
    std::cout << "Changed y = " << std::hex << *addr_of_y << '\n';

    double* addr_of_z = reinterpret_cast<double*>(&obj);
    ++addr_of_z;
    std::cout << "Initialized z = " << std::hexfloat << *addr_of_z << '\n';
    *addr_of_z = 0xAAAAp0;
    std::cout << "Changed z = " << std::hexfloat << *addr_of_z << '\n';
    //calling print_x()
    asm
    (
        "leaq	-32(%rbp), %rax\n\t"
        "movq	%rax, %rdi\n\t"
	    "call	_ZN1A7print_xEv\n\t"
    );
//calling print_y()
    asm
    (
        "leaq	-32(%rbp), %rax\n\t"
	    "movq	%rax, %rdi\n\t"
	    "call	_ZN1A7print_yEv\n\t"
    );
//calling print_z()
    asm
    (
        "leaq	-32(%rbp), %rax\n\t"
	    "movq	%rax, %rdi\n\t"
	    "call	_ZN1A7print_zEv\n\t"
    );
    return 0;
}