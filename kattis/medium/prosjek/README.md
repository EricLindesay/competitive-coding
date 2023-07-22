# Prosjek
- [Problem](#problem)
- [Solution](#prosjek.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/prosjek)

### Description

Slavko decided to challenge Mirko! He gave him a real number
`P` and a bag full of pieces of paper with exactly one number between `1` and `5` inclusive written on each paper.

There is an unlimited quantity of each type of paper.

Mirko’s task is to pick the minimum number of papers in a way that the average of the numbers written on them equals exactly `P`.

### Input
First and only line of input contains real number `P`. `P` will have between 1 and 9 decimal places, inclusive `(1 <= P <=
5)`.

### Output
First and only line of output should contain five nonnegative integers – numbers of ones, twos, threes, fours and fives used, respectively. If there are multiple solutions, output any one of them.


### Examples
```
Input
5.0
Output
0 0 0 0 1
```
```
Input
4.5
Output
0 0 0 1 1
```
```
Input
3.20
Output
2 0 0 1 2
```


## Solution

### Non-minimal solution
My idea is slowly converge onto the answer. 
First, round the number. That is your first choice. Now, is that choice less or greater than the goal? Less? Add on the next smallest number (or any smaller number which gets a closer result).
Greater? Do the same but for a higher number. I also don't think this guarantees the minimum number of pieces of paper used.

When submitting this, I got wrong answer for the second test case, implying that it isn't minimal.

[notminimal.cpp](./notminimal.cpp)

### Adjacent number solution
When implementing the non-minimal solution, for the input `3.20`, I got the output `0 0 4 1 0`. This made me think, can we just do it so it only uses the floor and ceiling. The problem with this is it may not be the minimum number of pieces of paper. However, you can then do some logic (after you have the initial output) to then say "well, instead of using 2 `3` papers, use a `1` paper and a `5` paper" but not that example because that doesn't reduce the total number of papers at all. 

While thinking about this, something else appeared in my mind. Maybe, if all the numbers have a common denominator, divide by the common denominator (because the average will still be the same).

Lets try the common denominator one first.

Common denominator is better, it passes more test cases, but still not all of them. There is something else I am missing which should allow you to decrease the number of papers used (or my method is wrong).

[commondenominator.cpp](./commondenominator.cpp)

Something else you can do is merge 1 and 5 into two 3s or 2 and 4 into two 3s. Doing this (and its reverse), you may be able to get a better GCD and be able to divide it for a better solution.