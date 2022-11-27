#include <memory>
template <typename Data>
class Tree {
    struct Node {
        std::unique_ptr<Node> left, right;
        Data d; // предполагаем некопируемые данные
    };
    std::unique_ptr<Node> top_;
    //void release_subtree(unique_ptr<Node> u) {} - рекурсия, но можно переписать...
    //решение в докладе CppCon 2016: Herb Sutter "Leak-Freedom in C++... By Default"
    //https://youtu.be/JfmTagWcqoE?t=1015
};