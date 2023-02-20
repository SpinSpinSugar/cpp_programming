//Instead of three, let's implement Directed Acyclic Graph (DAG)
// can't use unique, because we need double ownership
//              Node
//             /    \
//            Node  Node
//             \    /
//              Node <--double ownership
// DAG can be implemented as forest, but...
#include <memory>
template <typename Data>
class Tree {
        struct Node : std::__enable_shared_from_this<Node> {
            std::shared_ptr<Node> left, right;
            Data d; // предполагаем некопируемые данные
        };
        std::shared_ptr<Node> top_;
    public:
        std::shared_ptr<Node> find(int inorder_pos);
        //can be better
};