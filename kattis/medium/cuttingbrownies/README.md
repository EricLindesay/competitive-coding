# Cutting Brownies
- [Problem](#problem)
- [Solution](#cuttingbrownies.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/cuttingbrownies)

### Description
John Horton Conway (1937-) is a British mathematician withmany contributions to mathematics. He is famous for theinvention of the cellular automaton, more popularly known asthe “Game of Life.” This problem is inspired by a game Conwayinvented in the 1970s.

This game is played using a rectangular sheet of browniesfresh out of the oven. The players are Harry Horizontal andVicky Vertical. Initially, there is a single piece consistingof `B * D` connectedsquares (the individual brownies).

At each turn, a player chooses one of the remaining piecesand if possible, cuts it into two smaller pieces such that bothpieces have integer breadth and depth. Harry may make onlyhorizontal cuts, Vicky only vertical cuts. Pieces may not berotated before or after a cut. If a player cannot cut any ofthe remaining pieces, that player loses.

Let’s consider some examples. The simplest game is . In this case, neither Harry norVicky can make a move, so whoever starts loses. On the otherhand, is a win for Harry, no matter whostarts. Similarly, is a win for Vicky, no matter whostarts.

Consider , which is a loss for whoeverstarts. For instance, if Vicky starts, her only move leavesHarry with , and once he cuts any of thepieces, Vicky is left with , , (in any order) and thus againwithout moves. For reasons of symmetry, Harry loses if he ismade to start.

Intuition might tell us that Vicky should tend to win if theinitial sheet is broader than it is deep (since such sheetsyield more opportunities for vertical cuts), but consider. If Harry starts, his onlypossible move leaves Vicky with , and a win. But if Vicky starts,any possible move leaves Harry with , . Harry responds and leaves Vickywith , , , which Vicky will eventually losesince there are no moves left in the `2` sheets and whoever makes the firstmove on loses.

On the other hand, is a winner for Vicky, no matter whostarts. If Harry starts, he runs out of moves after his firstcut. If Vicky starts, her best move is to cut in the center,leaving Harry with , , which he loses because eachgame is lost by whoever movesfirst.
Given the initial size of the sheet, and given who startsthe game, write a program that computes if the starting playerhas a strategy to force a win!

### Input
The first line contains an integer `1 <= N <= 10` denoting the numberof test cases that follow. Each test case consists of a singleline containing two integers `B` and `D`, and a string `S`. Here `B` denotes the initial breadth of thesheet (`1 <= B <= 500`),`D` denotes the initialdepth of the sheet (`1 <= D <=500`) and `S` iseither Harry or Vicky depending on whether Harry or Vicky movesfirst.

### Output
For each test case, output whether the player who starts canforce a win in the game. Output the player’s name followed bycan win or cannot win.

### Examples
```
Input
5
1 1 Harry
2 2 Vicky
3 2 Vicky
4 2 Vicky
6 8 Harry
Output
Harry cannot win
Vicky cannot win
Vicky cannot win
Vicky can win
Harry can win
```


## Solution
Do two considerations, Harry starting and Vicky starting.

Harry's steps = height
Vicky's steps = width

If Vicky starts, multiply Harry's steps by two.
If Harry starts, multiply Vicky's steps by two.

Vicky will win if the initial sheet is broader than it is deep.

[cuttingbrownies.cpp](./cuttingbrownies.cpp)