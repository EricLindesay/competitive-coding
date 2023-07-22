# Contest Construction
- [Problem](#problem)
- [Solution](#contestconstruction.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/contestconstruction)

### Description

The ICPC NAC staff have written a number of problems andwish to construct a problem set out of them. Each problem has apositive difficulty rating.
A contest has a Nice difficulty distribution if,when the difficulties of the problems are sorted in ascendingorder, every problem after the second has a difficulty ratingless than or equal to the sum of the difficulty ratings of thetwo problems immediately preceding that problem.
Given the difficulty ratings of a set of problems and thenumber of problems desired for the set, count the number ofproblem sets with Nice difficulty distributions. Twoproblem sets are distinct if and only if there is some problemin one problem set but not in the other. (Specifically, notethat two problem sets are the same even if the problems arepermuted.)

### Input
The first line of input contains two integers `n` (`3<= n <= 50`) and `k` (`3<= k <= 18, k <= n`), where `n` is the number of problems thejudges have written, and `k` is the number of problems theywish to put in the problem set.
Each of the next `n`lines contains a single integer `d` (`1<= d <= 10^9`). These are the problemdifficulties.

### Output
Output a single integer, which is the number of possibleproblem sets with Nice difficulty distributions.

### Examples
```
Input
5 4
2
1
4
3
5
Output
4
```
```
Input
8 5
1
2
3
5
8
13
21
34
Output
4
```


## Solution

[contestconstruction.cpp](./contestconstruction.cpp)