# 1.6 - harshad-numbers
- [Problem](#problem)
- [Solution](#harshad-numbers.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/harshadnumbers)

### Description
We’re all familiar with harshad numbers. For this problem, you will ... what’s that? You aren’t familiar with harshad numbers? They’re also known as Niven numbers – does that ring a bell?? Anything???

Well, it’s a simple enough concept. A harshad number is a number which is evenly divisible by the sum of its digits. For example, `24`
is a harshad number: the sum of its digits is `2+4 = 6` and `24` is divisible by `6`. `156` is also a harshad number, since `1+5+6=12` and `156 = (12)(13)`. `157` is NOT a harshad number since it is not divisible by `1+5+7 = 13`.

OK, let’s start over.

We’re all familiar with harshad numbers. For this problem, you will be given a number `n` and must find the smallest harshad number `>= n`.

### Input
Input consists of a single line containing a positive integer `n <= 1000000000`.

### Output
Display the smallest harshad number greater than or equal to `n`.

### Examples
```
Input
24
Output
24
```

```
Input
25
Output
27
```

```
Input
987654321
Output
987654330
```

## Solution

Just do it brute force as you would expect.

[harshad-numbers.cpp](./harshad-numbers.cpp)

Solved!