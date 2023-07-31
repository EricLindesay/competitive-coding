# Popcorn
- [Problem](#problem)
- [Solution](#popkorn.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/popkorn)

### Description
 The culmination of the Galactic Popcorn Festival G-Pop is undoubtedly the competitive eating event.
First, the participants are separated into four groups of equal size. Then each participants competes against every other member of the same group; the goal is to eat half a bag of popcorn faster than the opponent. The winner of each group proceeds to one of the two semi-finals. The two losers of the semi-finals then compete for third place, and finally the two winners compete for winning the entire contest.
A record number of contestants is expected this year, so the organizers need your help in computing the total number of bags of popcorn needed.
The figure below shows an example with `n=12` participants. Each of the four groups (each consisting of `\frac{12}{4}=3` partipants) needs `3` bags of popcorn for the all-play-all matches. The two semi-finals each need a bag, and so do the matches for third and first place. The total number of bags needed is `12 + 2 + 1 + 1=16`. 

### Input
A single integer `4 <= n <= 10^{18}`, the number of participants. The number `n` is divisible by `4`.

### Output
The number of bags of popcorn needed.
Points
There are two test groups, each worth 50 points: Group Points Constraints 1 50 `n <= 10^6` 2 50 No further constraints on `n` 

### Examples
```
Input
12
Output
16
```
```
Input
28
Output
88
```
```
Input
4
Output
4
```


## Solution

[popkorn.cpp](./popkorn.cpp)