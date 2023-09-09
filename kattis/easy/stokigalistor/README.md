# Messy lists
- [Problem](#problem)
- [Solution](#stokigalistor.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/stokigalistor)

### Description

Doris has just started to program, and is participating in their first programming competition. She has encountered a problem that can be solved by sorting some cool integers. She decides to use the built-in sorting function in the revolutionary new programmering language Meowscript. However, the language isn’t completely finished and its sorting function seems to be a little buggy.
Help Doris determine how many elements are in the wrong index in the incorrectly sorted list of integers, compared to the same list if it had been properly sorted in increasing order.

### Input
The first row contains an integer `N` (`1<= N <= 10^6`), the number of elements in the list. The second row contains the `N` integers `0<= A_ i <= 10^9` that make up the incorrectly sorted list.

### Output
Print one integer - the number of elements in the list that are in the wrong position.
Grading
Your solution will be tested on a number of test-case groups. To receive points for a group, your solution must correctly solve every test-case in the group. Group Point value Restrictions `1` `20` `N <= 2` `2` `20` The built-in sorting function sorts in decreasing order `3` `20` `N <= 1000` `4` `40` No further restrictions 

### Examples
```
Input
5
1 1 2 3 5
Output
0
```
```
Input
7
3 1 4 1 5 9 2
Output
6
```


## Solution
Just sort the array yourself and compare each number.

[stokigalistor.cpp](./stokigalistor.cpp)

Solved!