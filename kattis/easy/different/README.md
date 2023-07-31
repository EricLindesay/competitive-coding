# A Different Problem
- [Problem](#problem)
- [Solution](#different.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/different)

### Description

Write a program that computes the difference between non-negative integers.

### Input
Each line of the input consists of a pair of integers. Each integer is between `0` and `10^{15}` (inclusive). The input is terminated by end of file.

### Output
For each pair of integers in the input, output one line, containing the absolute value of their difference. 

### Examples
```
Input
10 12
71293781758123 72784
1 12345677654321
Output
2
71293781685339
12345677654320
```


## Solution
Very simple problem, the only thing you need to take care of is that the two numbers can be up to `10^{15}` so you need to store them in a `long long` each.

[different.cpp](./different.cpp)

Solved!