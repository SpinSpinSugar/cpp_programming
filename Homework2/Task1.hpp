#include <iostream>

class MyArray {
    int* arr;
    size_t size_;
public:
    MyArray() : arr(nullptr), size_(0) { std::cout << "Default ctor\n";}
    explicit MyArray(size_t sz) : arr(new int[sz]), size_(sz) {std::cout << "Ctor\n";}
    MyArray(const MyArray& rhs) : arr(new int[rhs.size_]), size_(rhs.size_) {
        std::cout << "Copy ctor\n";
        my_memcpy(this->arr, rhs.arr, rhs.size_);
    }
    MyArray(MyArray&& rhs) : arr(rhs.arr), size_(rhs.size_) {
        std::cout << "Move ctor\n";
        rhs.arr = nullptr;
    }
    ~MyArray() {
        std::cout << "Dtor\n"; 
        delete[] arr;
    }    
    MyArray& operator=(const MyArray& rhs) & {
        std::cout << "op=\n";
        this->size_ = rhs.size_;
        my_memcpy(this->arr, rhs.arr, rhs.size_);
        return *this;
    }
    MyArray& operator=(MyArray&& rhs) {
        std::cout << "Move assigment\n";
        if (*this == rhs) return *this;
        size_ = rhs.size_;
        std::swap(arr, rhs.arr);
        return *this;
    }
    int& operator[](size_t idx) { return *(this->arr + idx); }
    friend bool operator==(const MyArray& rhs, const MyArray& lhs);
    int& get(size_t idx) & { return *(this->arr + idx); }
    void set(size_t idx, int val) { *(this->arr + idx) = val; }
    const size_t size() { return size_; }
    void print() {
        for (int i = 0; i < size_; ++i) {
            std::cout << (*this)[i];
        }
        std::cout << '\n';
    }
private:
    static void my_memcpy(int* dst, const int* src, size_t sz) {
        while (sz) {
            *(dst++) = *(src++);
            --sz;
        }
    }
};

bool operator==(const MyArray& rhs, const MyArray& lhs) {
    return (rhs.arr == lhs.arr);
}