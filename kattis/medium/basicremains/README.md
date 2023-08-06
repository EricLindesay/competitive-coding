# Basic Remains
- [Problem](#problem)
- [Solution](#basicremains.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/basicremains)

### Description
 Given a base `b` and two non-negative base-`b` integers `p` and `m`, compute `p \bmod m` and print the result as a base `b` integer. `p \bmod m` is defined as the smallest non-negative integer `k` such that `p = am + k` for some integer `a`.

### Input
Input consists of a number of cases (at most `1000`). Each case is represented by a line containing three non-negative integers. The first, `b`, is a base-`10` number between `2` and `10`. The second, `p`, contains up to `1000` digits between `0` and `b-1`. The third, `m`, contains up to `9` digits between `0` and `b-1`. The last case is followed by a line containing `0`.

### Output
For each test case, print a line giving `p \bmod m` as a base-`b` integer. 

### Examples
```
Input

2 1100 101
10 123456789123456789123456789 1000
0
Output

10
789
```


## Solution

### Initial Idea
At first I did it how you would do long division on paper. This kept on failing on the first hidden test case and I'm not sure why.

[basicremains.cpp](./basicremains.cpp)

### More thought
After more thought and some help from the interwebs, I realised you can just do the mod everytime you add on the big number and don't have to do checks to see if its less than. You also don't need to convert to and from decimal. You can keep it in decimal the entire time.  

[answer.cpp](./answer.cpp)

Solved!