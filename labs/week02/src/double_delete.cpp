int main() {
    int* p = new int{42};
    int* q = p;

    delete p;

    // Intentionally invalid for the AddressSanitizer exercise.
    delete q;

    // TODO: In a comment, explain why two pointer variables do not imply two allocations.
    /*
    The new int{42} dynamically allocates memory for the int object,
    while the q = p only copies the address of the int object that is stored in pointer p to pointer q,
    without creating a new object.
    Both pointer variables contain the address of the same object.
    */
}

/*
- the error category: attempting double-free
- the invalid-access line: 8
- the allocation site: 2
- the release site: 5
*/