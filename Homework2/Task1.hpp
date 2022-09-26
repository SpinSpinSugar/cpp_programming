#include <iostream>

class MyArray {
    struct Buffer {
        int* arr;
        size_t size;
        Buffer() : arr(nullptr), size(0) { std::cout << "Default ctor\n";}
        Buffer(size_t sz) : arr(new int[sz]), size(sz) { std::cout << "Ctor\n";} 
        Buffer(const Buffer& rhs) : arr(new int[rhs.size]), size(rhs.size) {
            std::cout << "Copy ctor\n";
            my_memcpy(this->arr, rhs.arr, rhs.size);
        }
        Buffer(Buffer&& rhs) : arr(rhs.arr), size(rhs.size) {
            std::cout << "Move ctor\n";
            rhs.arr = nullptr;
        }
        ~Buffer() {
            std::cout << "Dtor\n"; 
            delete[] arr;
        }
        Buffer& operator=(const Buffer& rhs) & {
            std::cout << "op=\n";
            this->size = rhs.size;
            my_memcpy(this->arr, rhs.arr, rhs.size);
            return *this;
        }
        Buffer& operator=(Buffer&& rhs) {
            std::cout << "Move assigment\n";
            if (*this == rhs) return *this;
            size = rhs.size;
            std::swap(arr, rhs.arr);
            return *this;
        }
        static void my_memcpy(int* dst, const int* src, size_t sz) {
            while (sz) {
                *(dst++) = *(src++);
                --sz;
            }
        }
        friend bool operator==(const Buffer& rhs, const Buffer& lhs) {
                return (rhs.arr == lhs.arr);
        }
    };
    Buffer buf;
public:
    MyArray(): buf() {};
    explicit MyArray(size_t sz): buf(sz) {};
    MyArray(const MyArray& rhs): buf(rhs.buf) {};
    MyArray(MyArray&& rhs) : buf(rhs.buf) {};
    ~MyArray() {};
    MyArray& operator=(const MyArray& rhs) & { buf = rhs.buf; return *this; };
    MyArray& operator=(MyArray&& rhs) { buf = std::move(rhs.buf); return *this; };
    int& operator[](size_t idx) { return *(buf.arr + idx); }
    int& get(size_t idx) & { return *(buf.arr + idx); }
    void set(size_t idx, int val) { *(buf.arr + idx) = val; }
    const size_t size() { return buf.size; }
    void print() {
        for (int i = 0; i < buf.size; ++i) {
            std::cout << (*this)[i];
        }
        std::cout << '\n';
    }
};
