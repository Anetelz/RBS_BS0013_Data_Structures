#include <iostream>

int main() {
    int value = 42;
    int* p = nullptr; // A null pointer - the pointer intentionally points to no object

    std::cout << "initially null: " << std::boolalpha << (p == nullptr) << '\n';

    p = &value; // A valid pointer - pointer points to a live object
    if (p != nullptr) {
        std::cout << "live value: " << *p << '\n';
    }

    int* dangling = nullptr;
    {
        int temporary = 99;
        dangling = &temporary;
        std::cout << "inside scope: " << *dangling << '\n';
    }

    // TODO: Explain why dangling must not be dereferenced here.
    // Currently dangling points to an object that no longer exists, as the variable 'temporary' was declared in {} and destroyed after {} ended.
    // Dereferencing a dangling pointer would lead to an undefined behavior.
    // Do not add: std::cout << *dangling;

    dangling = nullptr;
    std::cout << "dangling reset to null: " << (dangling == nullptr) << '\n';
}
