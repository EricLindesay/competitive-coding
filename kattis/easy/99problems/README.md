# 99 Problems
- [Problem](#problem)
- [Solution](#99problems.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/99problems)

### Description

Ingrid is the founder of a company that sells bicycle parts.   She used to set the prices of products quite arbitrarily, but   now she has decided that it would be more profitable if the   prices end in `99`.

You are given a positive integer `N`, the price of a product. Your task   is to find the nearest positive integer to `N` which ends in `99`. If there are two such numbers   that are equally close, find the bigger one.

### Input
The input contains one integer `N` (`1   <= N <= 10^4`), the price of a product. It is   guaranteed that the number `N` does not end in `99`.

### Output
Print one integer, the closest positive integer that ends in   `99`. In case of a tie,   print the bigger one.

### Examples
```
Input
10
Output
99
```
```
Input
249
Output
299
```
```
Input
10000
Output
9999
```


## Solution
Use mod to work out whether to round up or down.
Then use integer division by 100 to set the new numbers.

[99problems.cpp](./99problems.cpp)

Solved!