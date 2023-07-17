# 1dfroggerhard
- [Problem](#problem)
- [Solution](#1dfroggerhard.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/1dfroggerhard)

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
When you read in each number, keep track of what it points to and record that in a map, vector or something.  
Then, look at the magic number, find all numbers which point to a magic number, then find all numbers which point to those numbers. Do that recursively, counting how many unique numbers there are.  

You have to do this for every number which will take a while.  

This seems to work but right now is getting memory limit exceeded.  
Instead, I tried passing the seen vector by reference which is more memory efficient but causes the program to be too slow since you have to reset all values in it.  
[1dfroggerhard.cpp](./1dfroggerhard.cpp)