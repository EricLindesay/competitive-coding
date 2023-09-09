# How many 0's?
- [Problem](#problem)
- [Solution](#howmanyzeros.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/howmanyzeros)

### Description
 A Benedict monk No. 16 writes down the decimal representations of all natural numbers between and including `m` and `n`, `m <= n`. How many `0`’s will he write down?

### Input
Input consists of a sequence of lines. Each line contains two unsigned 32-bit integers `m` and `n`, `m <= n`. The last line of input has the value of `m` negative and this line should not be processed. There are at most `15, 000` test cases.

### Output
For each line of input print one line of output with one integer number giving the number of `0`’s written down by the monk. 

### Examples
```
Input

10 11
100 200
0 500
1234567890 2345678901
0 4294967295
-1 -1
Output

1
22
92
987654304
3825876150
```


## Solution

[howmanyzeros.cpp](./howmanyzeros.cpp)