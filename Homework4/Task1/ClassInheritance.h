#include <iostream>

namespace Example1 {
    struct Base {
        std::string f = "BASE1";
    };

    struct Derived : public Base {
        std::string f = "DERIVED1";
    };

    void SameFieldsNameExpamle() {
        std::cout << "\n\nINHERITANCE CASTS EXAMPLE:\n";
        Base a;
        Derived b;
        std::cout << "Base1 size: " << sizeof(a) << " Derived1 size: " << sizeof(b) << '\n';
        std::cout << a.f << ' ' << b.Derived::f <<  ' ' << b.Base::f << '\n';
        std::cout << "\n\n";
    }
}
//#######################################################################################################//
namespace Example2 {
    struct Base {
        std::string a;
        Base() : a("BASE") {}
    };

    struct Derived : public Base {
        std::string b;
        Derived() : Base(), b("DERIVED2") {}
    };

    void InheritancePtrCasts() {
        std::cout << "\n\nINHERITANCE CASTS EXAMPLE:\n";

        Derived* obj = new Derived();
        std::cout << "starting fields of Derived: " << obj->a << ' ' << obj->b <<'\n';
        
        Base* obj2 = static_cast<Base*>(obj);
        std::cout << "static_cast Derived* to Base*: " << obj2->a << ' ' << /*obj2->b << */ '\n';

        Base* obj3 = dynamic_cast<Base*>(obj);
        std::cout << "dynamic_cast Derived* to Base*: " << obj3->a << ' ' << /*obj3->b << */ '\n';
        
        //DON'T DO THAT
        Base* obj4 = reinterpret_cast<Base*>(obj);
        std::cout << "reinterpret_cast Derived* to Base*: " << obj4->a << ' ' << /*obj3->b << */ '\n';


        Base* base = new Base();
        Derived* derived1 = static_cast<Derived*>(base);
        std::cout << "static_cast Base* to Derived*: " << derived1->a << ' ' << "!SEG FAULT IF CALLED!" /* << derived1->b */ <<'\n';

        /* Error: cannot ‘dynamic_cast’ ‘obj2’ (of type ‘struct Base2*’) to type ‘struct Derived2*’ (source type is not polymorphic)
        Derived2* derived2 = dynamic_cast<Derived2*>(base);
        std::cout << derived2->a << ' ' << derived2->b <<'\n';
        */

        Derived* derived3 = reinterpret_cast<Derived*>(base);
        std::cout << "reinterpret_cast Base* to Derived*: " << derived3->a << ' ' << "!SEG FAULT IF CALLED!" /* << derived3->b */ <<'\n';
        delete base;
        delete obj;
        std::cout << "\n\n";
    }
}

namespace Slicing {
    struct A {
        int a;
        A(int a_) : a(a_) {}
    };

    struct B : A {
        int b;
        B(int a_, int b_) : A(a_), b(b_) {}
    };

    void frankenshein() {
        std::cout << "\n\nSLICING PROBLEM:\n";
        B b(1, 2);
        A& sliced = b;
        std::cout << b.a << ' ' << b.b << '\n';
        B c(7, 8);
        sliced = c;
        std::cout << b.a << ' ' << b.b << '\n';
        std::cout << "\n\n";
    }
}

namespace Example3 {
    class Base {
    protected:
        std::string B;
    public:
        Base() : B("B") { std::cout << "Base\n"; }
        ~Base() { std::cout << "Base dtor\n"; }
    };

    class Derived1 : public virtual Base {
        std::string D1;
    public:
        Derived1() : Base(), D1("D1") { std::cout << "Derived1\n"; }
        ~Derived1() { std::cout << "Derived1 dtor\n"; }
    };

    class Derived2 : public virtual Base {
        std::string D2;
    public:
        Derived2() : Base(), D2("D2") { std::cout << "Derived2\n"; }
        ~Derived2() { std::cout << "Derived2 dtor\n"; }

    };

    class Son : public Derived1, public Derived2 {
        std::string S = "S";
    public:
        Son() : Base(), Derived1(), Derived2(),  S("D1") { std::cout << "Son\n"; }
        ~Son() { std::cout << "Son dtor\n"; }
        void printB() { std::cout << B << '\n'; }
    };

    void MultipleInheritance() {
        std::cout << "\n\nMULTIPLE INHERITANCE:\n";
        Son obj;
        obj.printB();
        std::cout << "\n\n";
    }
}

namespace Example4 {
    class Empty {};

    class Base {
    public:
        virtual ~Base() { std::cout << "virtual Base dtor\n"; }
    };

    class Derived : public Base {
    public:
        Derived() : Base() {}
        ~Derived() override { std::cout << "virtual Derived dtor\n"; }
    };

    void vtableExperiments() {
        std::cout << "\n\nVTABLE EXPERIMENTS:\n";
        std::cout << "Sizeof Empty = " << sizeof(Empty) << " without vtbl" << '\n';

        Derived d;
        
        std::cout << "Sizeof Base = " << sizeof(Base) << " with vtbl*" << '\n';
        std::cout << "\n\n";
    }
}