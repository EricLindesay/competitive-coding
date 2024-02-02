# Design HashMap
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/design-hashmap)

### Description
Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:


	- `MyHashMap()` initializes the object with an empty map.
	- `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
	- `int get(int key)` returns the `value` to which the specified `key` is mapped, or `-1` if this map contains no mapping for the `key`.
	- `void remove(key)` removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.


### Input


- `0 <= key, value <= 10^6`
- At most `10^4` calls will be made to `put`, `get`, and `remove`.




### Examples
```
Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
```


## Solution

### Initial Thoughts
My initial thought is that the input is only 10^6, so you could just create an array of integers which has 10^6 elements and then store it directly in those positions. This is O(1) in time complexity for everything, however, it does use a lot of memory.  

Since this would be very easy to implement (and a little bit cheat-y), I didn't implement this.  

So, other options?
You could do hashing to a linked list. Have a vector of linked lists which is something like 1000 elements wide, and then search each linked list linearly. This is good, but has time efficiency of about O(n/1000). You could also do other collision handling techniques but this is the easiest for me intuitively.  

You could also store the hash keys in a tree (binary sort tree). If you have a tree with each node containing the key-value pair you could then get O(logn) for put, get and remove. (Assuming the tree is balanced).
- You can do trees in a vector, using the left child = 2*i 	and right child is 2\*i +1 and parent is i/2. (Make sure to make the first element in the array blank so its 1 indexed).

### Linked Lists (Collision Handling)
This implements linked lists as the collision handling method and beats 87% of users with C++.  

[linked-list.cpp](./linked-list.cpp)

Solved!
