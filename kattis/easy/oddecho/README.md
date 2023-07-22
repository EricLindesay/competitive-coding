# Odd Echo
- [Problem](#problem)
- [Solution](#oddecho.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/oddecho)

### Description

ECHO! Echo! Ech...
You love shouting in caves to hear your words echoed back atyou. Unfortunately, as a hard-working software engineer you arenot lucky enough to get out that often to shout in caves.Instead, you would like to implement a program that serves as areplacement for a cave.
Every now and then, you want to input a few words into theprogram and have them echoed back to you. However, as is wellknown, if you shout too quickly in a cave, the echo might causeinterference with the new words you say. More specifically,every other word you say will interfere with the echo of yourprevious word. Thus only the first, third, fifth, and so on,words will actually produce an echo.
Your task is to write a program that simulates thisbehavior.

### Input
The first line of the input contains an integer `N` (`1<= N <= 10`).
The next `N` lines eachcontains a word. Each word is at most `100` letters long, and contains onlyletters ‘a-z‘.

### Output
Output the odd-indexed (i.e. first, third, fifth, and so on)words in the input.
Scoring
Your solution will be tested on a set of test groups, eachworth a number of points. To get the points for a test groupyou need to solve all test cases in the test group.GroupPointsConstraints`1``1``N` is always`5``2``1`No additional constraints

### Examples
```
Input
5
hello
i
am
an
echo
Output
hello
am
echo
```
```
Input
10
only
if
these
oddindexed
words
appear
are
you
correct
output
Output
only
these
words
are
correct
```


## Solution

[oddecho.cpp](./oddecho.cpp)

Solved!