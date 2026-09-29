# Week 4 Reflection

Answer concisely after your implementation passes the public tests and sanitizer run.

1. Why can logical adjacency differ from physical address order in a linked list?
Linked list objects are not stored continuously in the same memory space. Instead, each object stores a pointer to a consecutive object that can be located anywhere else in the memory.
2. Why is numeric indexed access Θ(n) in a simple singly linked list?
To access each node, it is necessary to access the prevous node. For numeric indexed access, each consecutive node from head to the target needs to be visited to find the target.
3. Under what precise precondition is insertion by pointer rewiring Θ(1)?
A pointer to the node before the new node has to be accessible.
4. Why is `insert_after_first(target, value)` still Θ(n) in the worst case?
It is possible that the target value is the tail value. In this case, all previous nodes need to be visited before the target value is discovered. The insertion will be O(1) but the search can be O(n) in the worst case.
5. What invariant responsibility is added by caching `tail_`?
tail_ must point to the last node in the list and tail_-> next should be nullptr.
6. Why must a removed node's successor be obtained before deleting the node?
If the node is removed before the successor is obtained, the access to the successor can be lost. 
7. Give one structural bug that a memory sanitizer may not directly identify as a linked-list invariant violation.
An example could be tail_ pointing to a wrong node, not nullptr. This would be an invariant violation, but would not raise memory issues.
8. Why can dynamic-array traversal outperform linked-list traversal even though both are Θ(n)?
For linked-list traversal different memory spaces might need to be accessed. Because they are stored continuously in the same memory space, dynamic-array objects can be accessed more efficiently.
9. Give one workload favoring the Week 4 representation and one favoring Week 3's dynamic array.
If objects often need to be inserted or deleted in the middle of the list, it would be better to use the linked lists. If objects often need to be accessed by indexes, use of dynamic arrays would be preferable.
10. How do these representation choices prepare you to implement stacks and queues next week?
I would be better able to choose the representation based on which operations need to be performed more frequently. 
