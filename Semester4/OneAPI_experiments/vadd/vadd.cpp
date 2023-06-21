#include <iostream>
#include <vector>
#include <random>
#include <CL/sycl.hpp>

class vector_add;

constexpr int size = 1024;
constexpr auto sycl_read = sycl::access::mode::read;
constexpr auto sycl_write = sycl::access::mode::write;

void fill_random(std::vector<int>& vec) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist{1, 5000};
    for (auto& x : vec) x = dist(gen);
}

std::vector<int> vaddSeq(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> ans;
    ans.reserve(a.size());
    for (int i = 0; i < a.size(); ++i)
        ans.push_back(a[i] + b[i]);
    return ans;
}

int main() {
    std::vector<int> a(size);
    std::vector<int> b(size);
    std::vector<int> c(size);

    fill_random(a);
    fill_random(b);
    const auto ans = vaddSeq(a, b);

    cl::sycl::queue queue {sycl::default_selector_v};
    std::cout << "Selected device: " << queue.get_device().get_info<sycl::info::device::name>() << '\n';

    {
        sycl::buffer<int, 1> a_buf {a.data(), sycl::range<1>{size}};
        sycl::buffer<int, 1> b_buf {b.data(), sycl::range<1>{size}};
        sycl::buffer<int, 1> c_buf {c.data(), sycl::range<1>{size}};

        queue.submit([&](cl::sycl::handler& cgh) {
            auto a_acc = a_buf.get_access<sycl_read>(cgh);
            auto b_acc = b_buf.get_access<sycl_read>(cgh);
            auto c_acc = c_buf.get_access<sycl_write>(cgh);
            //SIMT
            cgh.parallel_for<vector_add>(sycl::range<1>{size}, [=](sycl::id<1> idx) {
                c_acc[idx] = a_acc[idx] + b_acc[idx];
                });
            });
    }

    for (int i = 0; i < size; ++i) {
        //std::cout << c[i] << "=" << ans[i] << '\n';
        assert(c[i] == ans[i]);
    }
    std::cout << "DONE";
}