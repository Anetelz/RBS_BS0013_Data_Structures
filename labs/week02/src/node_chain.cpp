#include <iostream>

struct Node {
    int value;
    Node* next = nullptr;
};

void print_chain(const Node* head) {
    // TODO: Traverse from head until nullptr and print each value followed by a space.
    
    if(head == nullptr){
        return;
    }

    std::cout << head->value << " ";
    print_chain(head->next);

    /*
    Use pointer-member syntax:
    - current->value
    - current->next
    Do not use indexing, arrays, or `std::vector` for this task.
    */
}

int main() {
    Node a{10};
    Node b{20};
    Node c{30};
    Node d{25};

    a.next = &b;
    b.next = &c;

    // Task 6A: temporarily rewire so traversal from a is 10 -> 30 -> null.
    a.next = &c;
    // Explain in a comment why b still exists even when unreachable from a.
    //b still exists because a.next = &c only changes the address of the pointer from &b to &c. It does not delete or modify b.
    // Task 6B: restore and then insert d so the final chain is:
    // 10 -> 20 -> 25 -> 30 -> null
    a.next = &b;
    b.next = &d;
    d.next = &c;

    print_chain(&a);
    std::cout << '\n';
}
