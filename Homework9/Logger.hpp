template <typename... Types>
class shell;

template <typename Res, typename... Args>
class shell<Res(Args...)> {
private:
    struct Base {
        virtual Base* get_copy() = 0;
        virtual Res operator()(Args...) = 0;
        virtual ~Base() = default;
    };

    template <typename Functor>
    struct Derived : public Base {
        Functor f;
        Base* get_copy() override {
            return new Derived<Functor>(f);
        }
        Derived(const Functor& f) : f(f) {}
        Res operator()(Args... args) override {
            return f(stratic_cast<Args>(args)...);
        }
        ~Derived() {}
    };

private:
    Base* f;

public:
    template <typename T>
    shell(const T& f):
        f(new Derived(f))
    {}

    ~shell() {
        delete f;
    }

    shell(const shell& other)
        : f(other.f->get_copy())
    {}

};