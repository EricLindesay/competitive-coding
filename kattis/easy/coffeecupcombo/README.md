# Coffee Cup Combo
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/coffeecupcombo)

### Description

Jonna is a university student who attends `n` lectures every day. Since most lectures are way too simple for an algorithmic expert such as Jonna, she can only stay awake during a lecture if she is drinking coffee. During a single lecture she needs to drink exactly one cup of coffee to stay awake.
Some of the lecture halls have coffee machines, so Jonna can always make sure to get coffee there. Furthermore, when Jonna leaves a lecture hall, she can bring at most two coffee cups with her to the following lectures (one cup in each hand). But note that she cannot bring more than two coffee cups with her at any given time.
Given which of Jonna’s lectures have coffee machines, compute the maximum number of lectures during which Jonna can stay awake.

### Input
The first line contains the integers `n` (`1 <= n <= 10^5`), the number of lectures Jonna attends.
The second line contains a string `s` of length `n`. The `i`’th letter is 1 if there is a coffee machine in the `i`’th lecture hall, and otherwise it is 0.

### Output
Print one integer, the maximum number of lectures during which Jonna can stay awake. 

### Examples
```
Input
10
0100010100
Output
8
```
```
Input
10
1100000000
Output
4
```
```
Input
1
0
Output
0
```
```
Input
10
0100010100
Output
8
```
```
Input
10
1100000000
Output
4
```
```
Input
1
0
Output
0
```


## Solution

[coffeecupcombo.cpp](./coffeecupcombo.cpp)

Solved!

Solved during the University of Nottingham coding competition