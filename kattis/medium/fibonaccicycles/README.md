# Fibonacci Cycles
- [Problem](#problem)
- [Solution](#fibonaccicycles.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/fibonaccicycles)

### Description

Yraglac loves number sequences. One of his favourites is the   classic Fibonacci numbers. He likes to set the base case as   `F_0 = F_1 = 1` and   `F_ n = F_{n-1} +   F_{n-2}`.
Now, one can only list out the same numbers so many times   before getting bored, so Yraglac came up with a new game: if he   took the sequence of Fibonacci numbers modulo some `k`, what is the index of the first   number in the new sequence that gets repeated? Yraglac only   considers numbers in the sequence starting from `n=2` since `F_0 = F_1` is boring.
Can you write a program to help Yraglac find the answer?

### Input
The first line contains a single integer `1 <=q Q <=q 500`, the number of   queries to follow.
The next `Q` lines each   contain a single integer `2 <=q   k <=q 1, 000`, the modulo to be used for the query. It   is guaranteed that some number in the sequence will be   repeated.

### Output
For each query, output the `n` such that `F_ n` is the first number in the   sequence of Fibonacci numbers modulo `k` that has a repeat at some point in   the sequence.

### Examples
```
Input
3
4
13
22
Output
4
5
8
```


## Solution

[fibonaccicycles.cpp](./fibonaccicycles.cpp)