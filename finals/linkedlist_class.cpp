#include <iostream>

class Linked_list;
class Node;
int main();

class Linked_list
{
};

class Node
{
public:
    Node(double const new_value, Node *const p_new_next_node);

    Node(Node const &orig);
    Node(Node &&orig);

    Node &operator=(Node const &rhs);
    Node &operator=(Node &&rhs);

    double value() const;
    Node *p_next_node() const;

    void value(double const new_value);
    void p_next_node(Node *const new_next_node);

private:
    double value_;
    Node *p_next_node_;
};

Node::Node(double const new_value, Node *const p_new_next_node) : value_{new_value}, p_next_node_{p_new_next_node}
{
}

double Node::value() const
{
    return value_;
}

Node *Node::p_next_node() const
{
    return p_next_node_;
}

void Node::value(double const new_value)
{
    value_ = new_value;
}

void Node::p_next_node(Node *const p_new_next_node)
{
    p_next_node_ = p_new_next_node;
}

int main()
{
    return 0;
}