# Week 5 Reflection — Circular Queue

Answer briefly after your implementation works.

1. Why is `enqueue` Θ(1) **worst case** in this fixed-capacity queue?   
In this case, the circular array does not need to be moved, nor is it neccessary to iterate through all the elements to find the back element position. The back element physical position can be calculated, if size_ and front_ are known.
2. Why is `dequeue` Θ(1) worst case?   
Dequeue() changes the front_ element to be the next element after the current front_. The new position is calculated, no elements are moved.
3. Why would a dynamically growing circular queue normally describe enqueue as **amortized Θ(1)** instead?   
With a dynamically growing circular queue, when the capacity needs to be increased, the array must be moved. With iterations of this process, the chance that the capacity will need to be increased significantly decreases.
4. In the expression `(front_ + i) % capacity()`, what does `i` mean: a physical index or a logical position?  
`i` is the logical position of the element. The expression itself calculates the physical index.
5. Why can the physical array still contain an old integer after `dequeue()` without that value remaining part of the logical queue?  
During dequeue() the current first_ value is not modified. Instead, the next element after the current first_ becomes the first_, size is decreased by 1.
6. Give one practical advantage of a circular array over a linked queue.  
Circular arrays are more memory-efficient. They do not need to store pointers for each node.
7. Give one practical limitation of this fixed-capacity circular queue.  
If the capacity is full, it will not be possible to enqueue new elements until the old ones are dequeued.
8. Which of these statements belongs to the **queue ADT**, and which belongs only to our **representation**?
   - first inserted remaining element is removed first; (queue ADT)
   - storage is a `std::vector<int>`; (representation)
   - elements may wrap around index 0; (representation)
   - `front()` returns the next element to be removed. (queue ADT)
