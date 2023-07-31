# Basic Programming 2
- [Problem](#problem)
- [Solution](#basicprogramming2.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/basicprogramming2)

### Description

You think you can code? This problem will test you on various basic programming techniques. You are given two integers `N` and `t`; and then an array `A` of `N` integers (`0`-based indexing). Based on the value of `t`, you will perform an action on `A`. `t` Action Needed `1` Print “Yes” if there are two integers `x \in A` and `y \in A` such that `x !=q y` and `x+y = 7, 777`, or “No” otherwise (without the quotes) `2` Print “Unique” if all integers in `A` are different; or print “Contains duplicate” otherwise (without the quotes) `3` Find and print the integer that appears `> \frac{N}{2}` times in `A`; or print `-1` if such integer cannot be found `4` Find and print the median integer of `A` if `N` is odd; or print both median integers of `A` if `N` is even (separate them with a single space) `5` Print integers in `A` that fall between a range [`100 ... 999`] in sorted order; (print a single space between two integers) 

### Input
The first line of the input contains an integer `N` and `t` (`3 <= N <= 200, 000`; `1 <= t <= 5`). The second line of the input contains `N` non-negative `32`-bit signed integers.

### Output
For each test case, output the required answer based on the value of `t`.
Scoring
There are `20` hidden test cases that test various requirements of this problem. All `20` test cases will be tested. Each hidden test case worth `5` points (the `5` sample test cases below worth `0` point). 

### Examples
```
Input
7 1
1 7770 3 4 5 6 7
Output
Yes
```
```
Input
7 2
1 2 3 4 5 6 7
Output
Unique
```
```
Input
7 3
1 1 1 1 2 2 2
Output
1
```
```
Input
8 4
8 1 4 3 6 7 5 2
Output
4 5
```
```
Input
7 5
210 999 1000 543 321 99 777
Output
210 321 543 777 999
```


## Solution
Very simple implementing the different processes. Took a lot of submissions debugging because I was doing `(n+1)/2` for the average instead of just `n/2`.

[basicprogramming2.cpp](./basicprogramming2.cpp)

Solved!