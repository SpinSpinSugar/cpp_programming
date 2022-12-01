"Shared pointer is as good as global variable...
when it comes to being able to reason about code that uses one" - Sean Parent

Example of method find in tree:
https://youtu.be/JrWl5INQybE?t=3996;
template <typename Data> class Tree {
    struct Node {
        std::unique_ptr<Node> left, right;
        Data d; // предполагаем некопируемые данные
    };
    std::unique_ptr<Node> top_;
public:
    ??? find (int inorder_pos); ----------------------------------->What to return?
    Data find(int inorder_pos); - BAD, data uncopiable
    Data* find(int inorder_pos); - Incapsulation problem
    const Data& find(int inorder_pos); - it's not container, it's ownership model
    Danling reference, because Data is uncopyable

    ###
    const T& vector::top() const; - T is copyable
    auto x = v.top(); - normal usage
    const auto& x = v.top(); - pretty bad
    ###

    std::unique_ptr<Node>& find(int inorder_pos); - also dangling vulnerability

    Нужно совместное владение!!!
...
};