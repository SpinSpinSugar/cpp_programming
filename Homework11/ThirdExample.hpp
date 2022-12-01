#include <memory>
#include <stack>

template <typename Data>
class Tree {
    struct Node {
        std::shared_ptr<Node> left, right;
        Data d;
    };

    std::shared_ptr<Node> top_;

    struct DFS_iterator;
    struct BFS_iterator;
public:
    DFS_iterator get_DFS_iterator() { DFS_iterator it{}; return it; }
    BFS_iterator get_BFS_iterator() { BFS_iterator it{}; return it; }
};