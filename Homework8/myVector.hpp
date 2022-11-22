#include <stdexcept>
#include <fstream>
//#include <type_traits>
namespace myVector__details {
    
    //copy of std::__log()
    inline size_t mylog(size_t x) {
        return 63^__builtin_clzl(x);
    }

    //Rounding size_t n to next power of 2
    inline size_t calc_cap(size_t n) {
        return n != 0
                    ? (1UL << (mylog(n) + 1UL))
                    : 0;
    }
};

template <typename T>
class myVector {
    T* data_;
    size_t size_;
    size_t capacity_;
public:
    myVector() : data_(nullptr), size_(0), capacity_(0) {}

    explicit myVector(size_t n, const T& value = T()) : data_(nullptr),
                                                        size_(n),
                                                        capacity_(myVector__details::calc_cap(n)) 
    {
        T* newdata = reinterpret_cast<T*>(new char[capacity_ * sizeof(T)]); //raw bytes
        size_t i = 0;
        try {
                for (; i < size_; ++i) {
                    new (newdata + i) T(value);
                }
            } catch (...) {
                for (size_t j = 0; j < i; ++j) {
                    newdata[j].~T();
                }
                delete[] reinterpret_cast<char*>(newdata);
                throw;
            }
        std::swap(data_, newdata);
    }
    
    myVector(const myVector& rhs) : data_(nullptr), size_(rhs.size_), capacity_(rhs.capacity_) {
        T* newdata = reinterpret_cast<T*>(new char[capacity_ * sizeof(T)]);
        size_t i = 0;
        try {
            for (; i < size_; ++i) {
                new (newdata + i) T(rhs[i]);
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                newdata[j].~T();
            }
            delete[] reinterpret_cast<char*>(newdata);
            throw;
        }
        data_ = newdata;
        newdata = nullptr;
    }
    
    myVector(std::initializer_list<T> initList) : data_(nullptr),
                                                  size_(initList.size()),
                                                  capacity_(myVector__details::calc_cap(initList.size()))
    {
        T* newdata = reinterpret_cast<T*>(new char[capacity_ * sizeof(T)]);
        size_t i = 0;
        try {
            for (auto it = initList.begin(), end = initList.end(); it != end; ++i, ++it) {
                new (newdata + i) T(*it);
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                newdata[j].~T();
            }
            delete[] reinterpret_cast<char*>(newdata);
            throw;
        }
        data_ = newdata;
        newdata = nullptr;
    }

    myVector(myVector&& rhs) : data_(rhs.data_), size_(rhs.size_), capacity_(rhs.capacity_) { rhs.data_ = nullptr; }
    
    myVector& operator=(const myVector& rhs) {
        if (this == &rhs) return *this;
        T* newdata = reinterpret_cast<T*>(new char[capacity_ * sizeof(T)]);
        size_t i = 0;
        try {
            for (; i < size_; ++i) {
                new (newdata + i) T(rhs[i]);
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                newdata[j].~T();
            }
            delete[] reinterpret_cast<char*>(newdata);
            throw;
        }
        data_ = newdata;
        newdata = nullptr;
        return *this;
    }
    
    myVector& operator=(myVector&& rhs) noexcept {
        if (this == &rhs) return *this;
        std::swap(data_, rhs.data_);
        std::swap(size_, rhs.size_);
        std::swap(capacity_, rhs.capacity_);
        return std::move(*this);
    }

    ~myVector() /*requires (!std::is_trivially_destructible_v<T>)*/ {
        for (size_t i = 0; i < size_; ++i) {
            //works for all types
            data_[i].~T();
        }
        delete[] reinterpret_cast<char*>(data_);
    }

    size_t size() const noexcept {
        return size_;
    }
    
    size_t capacity() const noexcept {
        return capacity_;
    }

    void reserve(size_t n) {
        if (n <= capacity_) return;
        //T* newarr = new T[calc_cap(n)]; - TERRIBLE, calls default ctor, but we don't need it
        T* newdata = reinterpret_cast<T*>(new char[n * sizeof(T)]); //uninitialized memory

        // Better use std::uninitialized_copy        
        size_t i = 0;
        try { // In case, if copy ctor throws an exception
            for (; i < size_; ++i) {
                //newarr[i] = arr[i]; - CAN'T call operator= for unitialized memory
                new(newdata + i) T(data_[i]); //placement new is calling copy ctor by this address
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                newdata[j].~T();
            }
            delete[] reinterpret_cast<char*>(data_);
            throw;
        }
        
        for (size_t i = 0; i < size_; ++i) {
            data_[i].~T();
        }
        
        delete[] reinterpret_cast<char*>(data_);
        data_ = newdata;
        capacity_ = n;
    }

    void resize(size_t n, const T& value = T()) {
        if (n > capacity_) reserve(n);
        if (n == size_) return;

        if (n < size_) {
            for (size_t i = n; i < size_; ++i) {
                data_[i].~T();
            }
            size_ = n;
            return;
        }
        
        size_t i = size_;
        try {
            for (; i < n; ++i) {
                new(data_ + i) T();
            }
        } catch(...) {
            for (size_t j; j < i; ++j) {
                data_[j].~T();
            }
        }
        size_ = n;
    }

    void push_back(const T& value) {
        if (size_ == capacity_) reserve(capacity_ != 0
                                                  ? 2 * capacity_
                                                  : 1); // if vector is empty, we should reserve 1 slot for new element
        new (data_ + size_) T(value);
        ++size_;
    }

    void pop_back() {
        data_[size_ - 1].~T();
        --size_;
    }

    T& operator[](size_t n) {
        return data_[n];
    }

    T& at(size_t n) {
        if (n >= size_) throw std::out_of_range("Index bigger than vector size");
        return data_[n];
    }

    const T& operator[](size_t n) const {
        return data_[n];
    }

    const T& at(size_t n) const {
        if (n >= size_) throw std::out_of_range("Index bigger than vector size");
        return data_[n];
    }

    T* data() {
        return data_;
    }

    const T* data() const {
        return data_;
    }


};
/*
public:
    void dump(std::ostream& os) const {
        for (size_t i = 0; i < size_; ++ i) {
            os << data_[i] << ' ';
        }
    }
*/

/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const myVector<T>& v) {
    v.dump(os);
    return os;
}
*/

template <typename T>
myVector<T> input_myVector(const std::string& Filename) {
    //TODO
    myVector<T> vec;
    std::filebuf fb;
    fb.open(Filename, std::ios::binary | std::ios::in);
    size_t sz = 0;
    size_t cap = 0;
    fb.sgetn(reinterpret_cast<char*>(&sz), sizeof(sz));
    fb.sgetn(reinterpret_cast<char*>(&cap), sizeof(cap));
    vec.reserve(cap);
    vec.resize(sz);
    for (int i = 0; i < vec.size(); ++i) {
        fb.sgetn(reinterpret_cast<char*>(&vec[i]), sizeof(T));
    }
    fb.close();
    return vec;
}
#include <iostream>
template <typename T>
void dump_myVector(const myVector<T>& vec, const std::string& Filename) {
    std::filebuf fb;
    std::string tmp = Filename;
    while (!fb.open(tmp, std::ios_base::binary | std::ios_base::out)) {
        std::cout << "Incorrect filename, please input new:\n";
        std::cin >> tmp;
    }
    size_t sz = vec.size();
    size_t cap = vec.capacity();
    fb.sputn(reinterpret_cast<char*>(&sz), sizeof(sz));
    fb.sputn(reinterpret_cast<char*>(&cap), sizeof(cap));

    for (int i = 0; i < vec.size(); ++i) {
        fb.sputn(reinterpret_cast<const char*>(&vec[i]), sizeof(T));
    }
    fb.close();
}