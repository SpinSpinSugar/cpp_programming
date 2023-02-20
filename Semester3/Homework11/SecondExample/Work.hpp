#include <iostream>
#include <string>
#include "Matrix.hpp"

class Table {
    my::Matrix<std::string> table;
    bool status;
public:
    void do_work() { status = true; }
    bool is_done() const { return status; }
};


//Observer - наблюдатель
class Boss {
    std::vector<Table> tables;
    void deadline() {
        for (const auto& x : tables) {
            if (!x.is_done()) std::cout << "WTF!!!\n";
        }
    }
};

