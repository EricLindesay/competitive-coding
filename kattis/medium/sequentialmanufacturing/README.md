# sequentialmanufacturing
- [Problem](#problem)
- [Solution](#sequentialmanufacturing.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/sequentialmanufacturing)

### Description
A certain manufacturing process consists of `N` different machines, through which raw material pass in order until it becomes the manufactured goods. The `i`’th machine takes `T_i` seconds to process a good when input.

A good moves automatically through the system once input into the first system. To give the system some tolerance with regards to timing, each machine `i` has an input area where `K_i` items waiting to be processed by that machine can be stored. This means that when machine `i` finishes processing a good, it is either passed on immediately to machine `i + 1` if it is free, and otherwise placed in its input area until that machine becomes free and can process the good. If a machine finishes a good, and the next machine is currently being used, and its input area is full, the system shuts down. If a machine and the one after it finish processing an item at the same time, that item does not need to be put in the input area of the second machine first.

You just got a huge order of goods, and now wonder – how quickly can you finish manufacturing these goods, without the system shutting down? You have an infinite supply of raw materials, and can choose at which times you put in items in machine `1`.

### Input
The first line contains the two integers `N (1 <= N <= 1000)`, the number of machines, and `P (1 <= P <= 10^9)`, the number of items that should be produced.

The next line contains the processing times `T_1, ..., T_N (1 <= T_i <= 10^9)`, which are all integers.

The next line contains the sizes of the input areas `K_2, ..., K_N (1 <= K_i <= 10^9)`, which are all integers. Note that the first machine does not have an input area.

### Output
Output the number of seconds it takes to manufacture all the requested items. Manufacturing is considered complete when the last item has been processed by the last machine.

### Examples
```
Input
2 3
1 5
100
Output
16
```

## Solution

Just do the `sum + highest * (n-1)`.

[sequentialmanufacturing.cpp](./sequentialmanufacturing.cpp)

Solved!