#include <iostream>

int main() {
    int* p = new int{42};
    delete p;

    // Intentionally invalid for the AddressSanitizer exercise.
    std::cout << *p << '\n';

    // TODO: In a comment, describe a correct lifetime/ownership repair.
    /* The pointer should no longer be dereferenced after the dynamically allocated value is deleted.
    To fix the code:
    1. do not dereference a dangling pointer;
    2. after the pointer p value is relesed, set it to nullptr or, if it is planned to use the pointer again, assign it a new live object before using it.
    */ 
}

/*
- the error category: heap-use-after-free
- the invalid-access line: 8
- the allocation site: 4
- the release site: 5
*/