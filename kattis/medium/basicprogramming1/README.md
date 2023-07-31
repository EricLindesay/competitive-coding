# Basic Programming 1
- [Problem](#problem)
- [Solution](#basicprogramming1.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/basicprogramming1)

### Description

You think you can code? This problem will test you on various basic programming techniques. You are given two integers `N` and `t`; and then an array `A` of `N` integers (`0`-based indexing). Based on the value of `t`, you will perform an action on `A`. `t` Action Needed `1` Print `7`, regardless of the content of `A` `2` Print “Bigger” if `A[0] > A[1]`, or Print “Equal” if `A[0] == A[1]`, or Print “Smaller” otherwise (without the quotes); Ignore other indices of `A`, if any `3` Print the median of three integers {`A[0]`, `A[1]`, and `A[2]`}; Ignore other indices of `A`, if any `4` Print the sum of all integers in `A` `5` Print the sum of all even integers in `A` `6` Apply modulo (%) `26` to each integer in `A`, Map integer `0`/`1`/`... `/`25` to character ‘a’/‘b’/`... `/‘z’, Finally, print the sequence of characters as a string (without the spaces) `7` a. Start from index `i = 0`; b. Jump to index `i = A[i]`; c. If the current index `i` is outside the valid bound of [0..`N`-1], print “Out” and stop; d. Else if the current index `i` is index `N`-`1`, print “Done” and stop; e1. Otherwise, go back to step b; e2. If doing this leads to an infinite loop, print “Cyclic” and stop; (all output are without the quotes) 

### Input
The first line of the input contains an integer `N` and `t` (`3 <= N <= 200, 000`; `1 <= t <= 7`). The second line of the input contains `N` non-negative `32`-bit signed integers.

### Output
For each test case, output the required answer based on the value of `t`.
Scoring
There are `20` hidden test cases that test various requirements of this problem. All `20` test cases will be tested. Each hidden test case worth `5` points (the `7` sample test cases below worth `0` point). 

### Examples
```
Input
7 1
1 2 3 4 5 6 7
Output
7
```
```
Input
7 2
1 2 3 4 5 6 7
Output
Smaller
```
```
Input
7 3
1 2 3 4 5 6 7
Output
2
```
```
Input
7 4
1 2 3 4 5 6 7
Output
28
```
```
Input
7 5
1 2 3 4 5 6 7
Output
12
```
```
Input
10 6
7 4 11 37 14 22 40 17 11 3
Output
helloworld
```
```
Input
3 7
1 0 2
Output
Cyclic
```


## Solution
Very simple, just do what it says.

[basicprogramming1.cpp](./basicprogramming1.cpp)

Solved!