# Line Them Up
- [Problem](#problem)
- [Solution](#lineup.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/lineup)

### Description

An eccentric coach asks players on the team to line up alphabetically at the start of practice. The coach does not tell the players whether they need to line up in increasing or decreasing order, so they guess. If they guess wrong, the coach makes them run laps before practice. Given a list of names, you are to determine if the list is in increasing alphabetical order, decreasing alphabetical order or neither.

### Input
The input consists of a single test case. The first line will contain the number `N` of people on the team (`2 <= N <= 20`). Following that are `N` lines, each containing the name of one person. A name will be at least two characters and at most `12` characters in length and will consist only of capital letters, and with no white spaces (sorry BILLY BOB and MARY JOE). Duplicates names will not be allowed on a team.

### Output
Output a single word: INCREASING if the list is in increasing alphabetical order, DECREASING if it is in decreasing alphabetical order, and otherwise NEITHER. 

### Examples
```
Input

5
JOE
BOB
ANDY
AL
ADAM
Output

DECREASING
```
```
Input

11
HOPE
ALI
BECKY
JULIE
MEGHAN
LAUREN
MORGAN
CARLI
MEGAN
ALEX
TOBIN
Output

NEITHER
```
```
Input

4
GEORGE
JOHN
PAUL
RINGO
Output

INCREASING
```


## Solution

[lineup.cpp](./lineup.cpp)

Solved!