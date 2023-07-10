# card-trick2
- [Problem](#problem)
- [Solution](#card-trick2.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/cardtrick2)

### Description

### Input

### Output

### Examples
```
Input
a b c
Output
c b a
```

## Solution

Think of it as a linked list. Then loop around this linked list doing the increments, if you see one you've already seen, skip it.

[card-trick2.cpp](./card-trick2.cpp)