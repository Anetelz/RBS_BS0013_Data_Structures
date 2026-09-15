#include <iostream>

int main() {
    int* p = new int{42}; // An int is dynamically allocated

    std::cout << "initial = " << *p << '\n';
    *p = 100; // Value changed throught the pointer
    std::cout << "changed = " << *p << '\n';

    // TODO: release the allocation exactly once.
    delete p; // The dynamically allocated int is released
    // TODO: after release, make p explicitly represent no object.
    p = nullptr;

    return 0;
}

