#include <iostream>

class Node {
  public:
    int value;
    Node* next_;
    Node (int v): value{v}, next_{nullptr} {}
    void print_list(); // provided code
};

class LinkedList {
  public:
    Node* head_;
    LinkedList(): head_{nullptr} {}
    void print_list(); // provided code

    void insert_value( int value );
    Node* find_value ( int search_value );
    Node* erase_value( int erase_value );
};

// insert a value into the list
void LinkedList::insert_value(int value) {
}

// find a value
Node* LinkedList::find_value ( int search_value ) {
    return nullptr;
}

// remove a value
Node* LinkedList::erase_value ( int erase_value ) {
    return nullptr;
}



int main() {

    return 0;
}


  //////////////////////////////////////////////////
 /// Provided code                              ///
//////////////////////////////////////////////////
// recursive print Node
void Node::print_list() {
    std::cout << value;
    if (next_ == nullptr) {
        std::cout << "}" << std::endl;
    } else {
        std::cout << ",";
        next_->print_list();
    }
}

// triggers recursive print
void LinkedList::print_list() {
    std::cout << "{";
    if (head_ == nullptr) {
        std::cout << "}" << std::endl;
    } else {
        head_->print_list();
    }
}