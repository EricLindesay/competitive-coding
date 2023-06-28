# Sum of Perfect Squares

- [Problem](#Problem)
- [Solution](#Solution)

## Problem
____________________________________________

[Problem Link](https://www.codewars.com/kata/5a3af5b1ee1aaeabfe000084/train/python)

The task is simply stated. Given an integer `n (3 < n < 109)`, find the length of the smallest list of perfect squares which add up to `n`. Come up with the best algorithm you can; you'll need it!  

Examples:
```py
sum_of_squares(17) = 2
# 17 = 16 + 1 (4 and 1 are perfect squares).
sum_of_squares(15) = 4
#15 = 9 + 4 + 1 + 1. There is no way to represent 15 as the sum of three perfect squares.
sum_of_squares(16) = 1
#16 itself is a perfect square.
```
Time constraints:
- 5 easy (sample) test cases: n < 20
- 5 harder test cases: 1000 < n < 15000
- 5 maximally hard test cases: 5e8 < n < 1e9
- 15 random maximally hard test cases: 1e8 < n < 1e9

## Solution
__________________
Initial thought was to just square root the number as many times as possible, reducing the number by that square root each time.   
However this doesn't work for 18 since `rt(18) = 4.4, rt(2) = 1, rt(1) = 1` and it should be `18 = 9 + 9`.

Better thought. This is just a change giving problem in disguise. Wouldn't have recognised that before uni I don't think.
Could also do hashing to remember the outputs but that only helps if the test cases are "compiled" into one.

I did the memory but it still isn't fast enough. I'm not really sure why.

You could save the array formed from the previous ones but I don't think that will be fast enough since you still have to do the same number of loops.
It will save some, if you do size restrictions so that it just doesn't loop that low.

[initial solution](sum_of_perfect_squares.cpp)
[recursion splitting](splitting.cpp)
[solution storing previous in an array](store_solutions.cpp)

Doing research, there seems to be a theorem `Lagrange's Four Square Theorem`.
[wikipedia link](https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem)
[good explanation](https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/)

[lagrangeTheorem.cpp](lagrangeTheorem.cpp)

Solved!