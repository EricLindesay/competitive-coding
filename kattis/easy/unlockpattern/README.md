# Unlock Pattern
- [Problem](#problem)
- [Solution](#unlockpattern.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/unlockpattern)

### Description
Mobile phones may require passcodes to unlock, but people sometimes forget their passcodes. An alternative is the 9-pivot unlock pattern. Some people find such a graphical pattern easier to remember than a sequence of digits. Formally, an unlock pattern is a single stroke that visits each of the nine pivots exactly once. The pattern may start at any pivot. It may pass a pivot multiple times but only the first time counts as a visit. The phone unlocks if the pivots are visited in a predefined secret order. A pattern is more complex if the total length of the stroke is longer. Given an unlock pattern, can you calculate its length? We assume that the pivots are aligned on a unit grid, and the stroke moves in a straight line between two consecutive pivots.

The sample input corresponds to the unlock pattern in the image.

### Input
The input has three lines. Each line has three non-zero digits separated by a single space. The digits describe the order in which the pivots are visited. Every digit from `1` to `9` appears exactly once.

### Output
Output the total length of the unlock pattern. Your answer is considered correct if it has an absolute or relative error of at most `10^{-6}` from the correct answer. 

### Examples
```
Input
6 1 9
5 2 8
4 3 7
Output
9.8284271247
```


## Solution

[unlockpattern.cpp](./unlockpattern.cpp)

Solved!