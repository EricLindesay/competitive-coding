# Mia
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/mia)

### Description
 Mia is a dice game for two players. Each roll consist of two dice. Mia involves bluffing about what a player has rolled, but in this problem we focus only on its scoring rules. Unlike most other dice games, the score of a roll is not simply the sum of the dice. Instead, a roll is scored as follows: Mia (`12` or `21`) is always highest. Next come doubles (`11`, `22`, and so on). Ties are broken by value, with `66` being highest. All remaining rolls are sorted such that the highest number comes first, which results in a two-digit number. The value of the roll is the value of that number, e.g. `3` and `4` becomes `43`. 

### Input
The input will contain multiple, distinct test cases. Each test case contains on a single line four integers `s_0 \ s_1 \ r_0 \ r_1` where `s_0 \ s_1` represent the dice rolled by player `1` and `r_0 \ r_1` represents the dice rolled by player `2`. The input will be terminated by a line containing `4` zeros.

### Output
For each test case, output which player won, or whether there was a tie, using exactly the format shown below. 

### Examples
```
Input

1 2 1 3
3 3 2 1
6 6 4 4
6 5 1 1
4 2 2 4
0 0 0 0
Output

Player 1 wins.
Player 2 wins.
Player 1 wins.
Player 2 wins.
Tie.
```
```
Input

1 2 1 3
3 3 2 1
6 6 4 4
6 5 1 1
4 2 2 4
0 0 0 0
Output

Player 1 wins.
Player 2 wins.
Player 1 wins.
Player 2 wins.
Tie.
```


## Solution

[mia/src/main.rs](./mia/src/main.rs)

Solved!