#include "int_linked_list.hpp"

#include <iostream>

int main() {
    IntLinkedList list;

    std::cout << "Week 4 linked-list lab\n";
    std::cout << "Initial state: size=" << list.size()
              << ", invariant=" << std::boolalpha << list.check_invariant() << '\n';

    // Add your own operation traces here while implementing the lab.

    list.push_front(1); // 1
    list.push_back(2); // 1,2
    list.push_front(3); //3,1,2
    list.push_back(4); //3,1,2,4
    
    std::cout << "First value: " << list.front() <<'\n';
    std::cout << "Last value: " << list.back() <<'\n';

    list.pop_front(); // 1,2,4
    list.insert_after_first(4,3); //1,2,4,3
    list.insert_after_first(1,7); //1,7,2,4,3
    list.pop_front(); //7,2,4,3
    list.erase_after_first(4); // 7,2,4


    std::cout << "First value: " << list.front() <<'\n';
    std::cout << "Last value: " << list.back() <<'\n';
    std::cout << "Contains 2: " << list.contains(2) <<'\n';
    std::cout << "Contains 8: " << list.contains(8) <<'\n';

    /*std::cout << "Testing clear() on a long list \n";
    list.clear(); 
    std::cout << "First value: " << list.front() <<'\n'; */

    /*std::cout << "Testing clear() on a one-node list \n";
    list.push_front(1);
    list.clear(); 
    std::cout << "First value: " << list.front() <<'\n'; */

    /*std::cout << "Testing clear() on an empty list \n";
    list.clear();  */

    return 0;
}
