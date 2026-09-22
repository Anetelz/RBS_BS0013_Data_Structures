# Week 3 Reflection — Dynamic Arrays

Complete this file briefly but precisely.

## 1. Size, capacity, and storage

1. Can `size()` be smaller than `capacity()`? Explain.
Yes, size() can be smaller than capacity(). Size represents the number of elements an array contains, and the capacity represents the number of elements the array can contain without needing to allocate more memory for them.
2. Why must `size()` never exceed `capacity()`?
If new elements were added to the array when the size matches the capacity, without increasing the capacity, it would cause undefined behavior. The array would have no more memory space for the new elements.
3. Does every `push_back` allocate? What did `vector_growth` show?
Not every use of `push_back` allocates more memory to the vector. `vector_growth` showed that more memory is allocated only if the size exceeds the capacity. If there is enough capacity, `push_back` only adds the element to the end of the vector, increasing the size by 1.
4. What does `data()` identify?
Function `data()` returns the address of the first element of the vector's array.

## 2. Reallocation and pointer validity

Why can a pointer to an element become invalid after a capacity-changing `push_back`? Explain using **storage lifetime**, not only address changes.
After a capacity-changing `push_back`, all of the array elements are moved to another place in memory. After the transfer, the old storage space is released and the objects in it get destroyed (the storage lifetime of each object in that space is ended). If there are any pointers that were pointing to an element in the old storage space, after the release of the storage space, that pointer points to an element with an ended lifetime. The pointer becomes a dangling pointer and its dereferencing causes undefined behaivor.

## 3. Invariants

State the two representation invariants used by `IntVector`. Why is checking an invariant after every mutating operation useful?
The two representation invariants are that size must be less or equal to capacity and that zero capacity and `nullptr` agree with each other. Checking and invariant after every mutating operation helps to immediately detect errors resulting from the operation.


## 4. Complexity

Fill in the table.

| Operation | Complexity | Why? |
|---|---|---|
| `at(i)` |O(1) |with an array can directly access each of the n elements|
| `push_back` without growth |O(1) |no allocation and no elements moved|
| `push_back` that reallocates |O(n)| n elements moved |
| `push_back` amortized over many appends |O(n^1)| as capacity doubles, it grows and reallocations become more and more rare |
| copy construction |O(n) |copies all n elements to another memory space|

Why does doubling capacity give amortized constant-time append even though some individual appends are linear?
As capacity doubles again and again, it grows and reallocations become more and more rare. 

## 5. Deep copy

What would go wrong if copying `IntVector` only copied `data_`, `size_`, and `capacity_` member-by-member? Name at least two correctness/ownership problems.
In this case both data_ pointers would point to the first element of the same array. Modifying the elements of one vector would affect the other vector as well. It could also be possible to mistakenly release the same memory twice.

## 6. STL comparison

Give one reason to use `std::vector<int>` in production code instead of this teaching implementation, and one reason implementing `IntVector` is still useful in a data-structures course.

Implementing the `std::vector<int>` would be a safer option as it comes from a standard, well-tested library. Implementing `IntVector` could help us better understand the work of dynamic arrays.
