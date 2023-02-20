#include <memory>
#include <utility>
#include "CImpl.hpp"

// Pimpl witout unique_ptr
struct CImpl0;

class Ifacade0 {
    CImpl0* impl_;
public:
//Big 5
    Ifacade0() : impl_(new CImpl0) {}
    Ifacade0(const Ifacade0& other) : impl_(new CImpl0{*other.impl_}) {}
    Ifacade0(Ifacade0&& other) : impl_(other.impl_) { other.impl_ = nullptr; }
    Ifacade0& operator=(const Ifacade0& rhs) {
        if (this == &rhs) return *this;
        CImpl0* tmp = new CImpl0{*rhs.impl_};
        //
        delete impl_;
        impl_ = tmp;
        return *this;
    }
    Ifacade0& operator=(Ifacade0&& rhs) {
        std::swap(impl_, rhs.impl_);
        return *this;
    }
    ~Ifacade0() { delete impl_; }
};

//Good pimpl
struct CImpl;

#ifndef CE
struct CImplDeleter {
    void operator()(CImpl*); // Define operator where size of CImpl is known
};

struct Ifacade {
    std::unique_ptr<CImpl, CImplDeleter> impl_;
    Ifacade() : impl_(nullptr) {};
};
#endif

#ifdef CE
struct Ifacade {
    std::unique_ptr<CImpl> impl_;
    Ifacade() : impl_(nullptr) {};
};
#endif

int main() {
    Ifacade a{};
}