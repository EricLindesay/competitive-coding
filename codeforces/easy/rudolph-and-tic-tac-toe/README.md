# rudolph-and-tic-tac-toe
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://codeforces.com/contest/1846/problem/B)

### Description
Rudolph invented the game of tic-tac-toe for three players. It has classic rules, except for the third player who plays with pluses. Rudolf has a 3 x 3 field  — the result of the completed game. Each field cell contains either a cross, or a nought, or a plus sign, or nothing. The game is won by the player who makes a horizontal, vertical or diagonal row of 3 of their symbols.

Rudolph wants to find the result of the game. Either exactly one of the three players won or it ended in a draw. It is guaranteed that multiple players cannot win at the same time

### Input
The first line contains one integer `t (1≤t≤104)` — the number of test cases.

Each test case consists of three lines, each of which consists of three characters. The symbol can be one of four: "X" means a cross, "O" means a nought, "+" means a plus, "." means an empty cell.

### Output
For each test case, print the string "X" if the crosses won, "O" if the noughts won, "+" if the pluses won, "DRAW" if there was a draw.

### Examples
```
Input
5
+X+
OXO
OX.
O+.
+OX
X+O
.XO
OX.
+++
O.+
X.O
+..
.++
X.O
+..
Output
X
O
+
DRAW
DRAW
```

## Solution

This is a very simple one, just look for three in a row and make sure that they are all the same and not a full stop.  

[rudolph-and-tic-tac-toe.cpp](rudolph-and-tic-tac-toe.cpp)

Solevd! within competition

Make sure that it was not hacked before doing solved again.