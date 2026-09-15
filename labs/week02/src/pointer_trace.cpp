#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    int* p = &a;
    int* q = p;

    // TODO: Before running, complete this trace in comments:
    // step                  a    b    p points to    q points to
    // after declarations    10   20   a              a

    *q += 5;
    // after *q += 5         15    20   a             a

    p = &b;
    // after p = &b          15    20   b             a

    *p += 7;
    // after *p += 7         15    27    b             a

    // TODO: Explain why reassigning p did not also reassign q.
    // Initially p points to a. q = p, meaning that q now also points to a, it is not a pointer to p. Changes in p does not affect q.

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "*p = " << *p << '\n';
    std::cout << "*q = " << *q << '\n';
}
