# Simple Addition
- [Problem](#problem)
- [Solution](#simpleaddition.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/simpleaddition)

### Description

Yup, yet another trivial problem. You just have to add two integers! Oh, not easy enough? Sure, let’s say that they’re positive as well. Now it should be trivial, right?

### Input
The input consists of two lines, each containing a positive integer less than `10^{10, 000}`. Oh right…I forgot to mention that the integers can be quite large.

### Output
One line containing the sum of the two integers. 

### Examples
```
Input

1337
42
Output

1379
```
```
Input

1
9999999999999
Output

10000000000000
```


## Solution
Store the two numbers as strings since they are too long to store in long longs.  
Then just add them together one character at a time and output the answer.  

[simpleaddition.cpp](./simpleaddition.cpp)

Solved!