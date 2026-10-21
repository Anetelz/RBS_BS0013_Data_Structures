# Week 6 Reflection — Linear-Probing Hash Map

Answer briefly after your implementation works.

1. Under suitable hashing and controlled load, why are lookup, insertion, and deletion described as **expected Θ(1)** rather than worst-case Θ(1)?  
In the worst case it is O(n) because there exists a possibility that the number of collisions could reach n. If the matching key was stored at the end after the last colision, it would require to go through all previous possible spots before finding it.
2. Give a set of integer keys that all collide when the table capacity is 7. What happens to their probe lengths?  
8, 15, 22, 29 would all have the initial index of 1. With each new collision, the probe lenght for the last added key would increase.
3. Why must lookup continue through a Deleted slot but may stop at an Empty slot?  
The Deleted slot means that a key was stored there before. If a new colliding key was added before the key was deleted, it would be stored somewhere after the currently Deleted slot. Since the necessary value could be stored after the Deleted slot, the lookup must continue. The Empty slot signifies that no values are or were stored in it or after it.
4. Why must insert_or_assign continue probing after finding a tombstone before deciding to insert there?  
It is possible that the key that it wishes to insert is already stored, but after the tombstone. If the key was inserted at the tombstone spot and another such value already existed after it, it would repeat. Therefore, the function must first remember the spot of the first tombstone, continue the lookup, make sure that such a value is not stored yet. After that it can insert the key at the place of the first tombstone if no matching value was found.
5. Why does increasing the load factor usually increase successful and unsuccessful probe lengths?  
The incerased load factor means that there are less free storage spaces in the table and that more collisions would happen. More table slots would need to be inspected during every lookup.
6. Why can changing the table capacity require reinserting or rehashing every live key?  
If the capacity was used to calculate the initial index value for each key, the initail index would change after capacity changes and the previously added keys could no longer be found as easily. To prevent that, reinserting or rehashing every live key might be necessary. 
7. How is **expected Θ(1)** hash-table lookup different from **amortized Θ(1)** dynamic-array append?  
The expected O(1) is based on the expectation that the hash-table values would be spread out enough to not couse too many collisions. The amortized O(1) for dynamic-array append means that O(1) is the average complexity cost of append over a large sequence of appends. There can still ocasionally be actions that requrie larger complexity, for example resizing of the array. Howerver, their cost is negligible.
8. Give one tradeoff between separate chaining and open addressing.  
Separate chaining requires more storage space. For the open addressing, as the table fills up, the collisions become more often and the probe lenghts increase faster. 