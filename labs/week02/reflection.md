# Week 2 Reflection

Answer briefly but precisely.

## 1. Pointer copying

Why does copying a pointer value not copy the pointed-to object?
Because the pointer stores the address to an object, not object itself. 

## 2. Reachability versus lifetime

Explain how an object can still be alive but no longer reachable by traversing from a particular head pointer.
This can happen if a pointer, which originally contained the address of the object and was used to traverse from a particular head pointer, gets assigned a new value. In this process the object, that the pointer originally pointed to, is not deleted or modified.

## 3. Dangling pointers

When a pointer becomes dangling, what changed: the pointer's stored numeric value, the target object's lifetime, or necessarily both?
The target object's lifetime ended.

## 4. Ownership responsibility

Why can two pointers to one dynamically allocated object not both independently `delete` it?
Even if both pointers point to the same dynamically allocated object, there is still only one object. The object can be deleted only once.

## 5. `nullptr`

Why does assigning `nullptr` to a raw pointer not release dynamically allocated storage?
Assigning nullptr only changes the value of the pointer from the objects address to nullptr. It does not affect the dynamically allocated object itself.

## 6. Linked traversal complexity

Why is traversal of `n` linked nodes Θ(n) even though following one `next` pointer is Θ(1)?
Because the traversal from the current node to the next node needs to be done n number of times.

## 7. Invariants

State two invariants that should hold for the final chain `10 -> 20 -> 25 -> 30 -> null`.
The last node should have a pointer to the next node set as `nullptr`.
Each current node should have a pointer to the next node in the intended sequence.
