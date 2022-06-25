# Table Decorations - 1800

- [Problem](#Problem)
- [Solution](#Solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/478/C)

You have *r* red, *g* green and *b* blue balloons. To decorate a single table for the banquet you need exactly three balloons. Three balloons attached to some table shouldn't have the same color. What maximum number *t* of tables can be decorated if we know number of balloons of each color?

Your task is to write a program that for given values *r*, *g* and *b* will find the maximum number *t* of tables, that can be decorated in the required manner.

### Input
The single line contains three integers `r, g and b (0 ≤ r, g, b ≤ 2·109)` — the number of red, green and blue baloons respectively. The numbers are separated by exactly one space.

### Output
Print a single integer t — the maximum number of tables that can be decorated in the required manner.

### Examples
```
Input
5 4 3
Output
4
```
```
Input
1 1 1
Output
1
```
```
Input
2 3 3
Output
2
```

### Note
In the first sample you can decorate the tables with the following balloon sets: "rgg", "gbb", "brr", "rrg", where "r", "g" and "b" represent the red, green and blue balls, respectively.


## Solution

### Average
My intial thought was that you just had to floor the average of the three numbers.  
This is wrong however because if you have something like `0 0 3`, the output should be 0, not one.  
Also if you have something like `0 1 5`, the output should be 1 even though the average is 2.  

The solution to this is to do `tables = min(average, sum_smallest_two)`.  
 
This works on my local machine but when I test it on the website, it doesn't work because of integer overflow, eventhough all of my numbers are longs. I have no clue why. This has caused 4 wrong submissions so far.

The reason was because the program gets run on a 32 bit machine, in which a long is only 32 bits, not the 64 I was expecting. The solution to this was to do all of the numbers as a long long which is 64 bits on both a 64 bit machine and a 32 bit machine.  

[average.cpp](average.cpp)  

Solved! 