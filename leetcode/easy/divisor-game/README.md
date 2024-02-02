# Divisor Game
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/divisor-game)

### Description
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number `n` on the chalkboard. On each player's turn, that player makes a move consisting of:


	- Choosing any `x` with `0 < x < n` and `n % x == 0`.
	- Replacing the number `n` on the chalkboard with `n - x`.


Also, if a player cannot make a move, they lose the game.

Return `true` *if and only if Alice wins the game, assuming both players play optimally*.

### Input


- `1 <= n <= 1000`




### Examples
```
Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
```

```
Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
```


## Solution

### DP
Create a table of possible game states and who wins. Based on turn
A state is a winning state if it can be divided into a losing state (for the opponent)

n | n_victory
--|----------
1 | false
2 | true
3 | Can alice subdivide 3 into a losing state? No, false
4 | true - Alice can divide this using 1
5 | false
6 | true - Alice can choose n%3 which goes to 3 which is a losing state

### Direct
Alice always wins on an even input so you could just do that.
I wanted to practice DP though.

[divisor-game.cpp](./divisor-game.cpp)

Solved!