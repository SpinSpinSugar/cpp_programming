#include <iostream>

class A {
    int x = 0xA;
    char y = 'B';
    double z = 0xFFFFp0;
    void print_x();
    void print_z();
    void print_y();
public:
    void print() {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};

void A::print_x() { std::cout << "x = " << x << '\n'; }
void A::print_y() { std::cout << "y = " << y << '\n'; }
void A::print_z() { std::cout << "z = " << z << '\n'; }

struct A_Hack {
    int x;
    char y;
    double z;
};

union U
{
    A obj;
    A_Hack hack_obj;
    U(): obj() {}
};


int main() {
    U tmp_union;
    tmp_union.obj.print();
    tmp_union.hack_obj.x = 0xBEEF;
    tmp_union.hack_obj.y = 'C';
    tmp_union.hack_obj.z = 1.5;
    tmp_union.obj.print();
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