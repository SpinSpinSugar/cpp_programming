#include <iostream>
#include <algorithm>
#include <vector>

void print(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v {5, 4, 3, 2, 1};
    print(v);
    mysort<std::vector<int>::iterator>(v.begin(), v.end());
    print(v);
    return 0;
}