#include <iostream>
#include <vector>

void input_tree(std::vector<std::pair<int,int>>& vec) {
    int size = 0;
    std::cin >> size;
    vec.reserve(size);
    int first = 0, second = 0;
    for (int i = 0; i < size; ++i) {
        std::cin >> first >> second;
        vec.emplace_back(first, second);
    }

}

int main() {
    std::vector<std::pair<int, int>> tree1;
    input_tree(tree1);
    std::vector<std::pair<int, int>> tree2;
    input_tree(tree2);
    
}
