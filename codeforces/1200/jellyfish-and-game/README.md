# Jellyfish and Game
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://codeforces.com/problemset/problem/1874/A)

### Examples
```
Input
4
2 2 1
1 2
3 4
1 1 10000
1
2
4 5 11037
1 1 4 5
1 9 1 9 8
1 1 1
2
1
Output
6
1
19
2
```

## Solution

Turn 1:
If J's lowest < G's highest, swap them
Otherwise J does nothing

Turn 2:
G swaps their lowest with J's highest. This is always done because J will always have a higher value due to turn 1.
G's lowest is either the original lowest or the one just given by J

Turn 3:
J swaps their lowest with G's highest

Turn 4:
G swaps them back

...


Keep J's first and second highest and lowest.
Keep G's first and second highest and first lowest.

[jellyfish-and-game.cpp](./jellyfish-and-game.cpp)
