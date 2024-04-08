# Add 'Em Up!
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/addemup)

### Description

Simon is a contestant on the new exciting game show, Add ’Em Up! In this show, contestants are given a set of cards with multi-digit numbers on them, and need to select two cards that add up to a given sum. However, to make things more interesting, the font that the cards are printed in (see below) means that certain cards will display different numbers if turned upside-down, and it is legal to turn either or both of the cards if necessary to generate the sum. Please help Simon win the game! 

### Input
The first line contains two integers, `n`, the number of cards, and `s`, the desired sum. The second line will contain `n` integers between `1` and `100, 000, 000` inclusive. You may assume that `1<= n<= 100, 000` and `2<= s<= 200, 000, 000`.

### Output
The output should be a single line consisting of the string YES if two cards can be chosen such that (in some orientation) they add up to `s`, and the string NO otherwise. 

### Examples
```
Input
3 66
15 21 22
Output
NO
```
```
Input
3 63
15 21 22
Output
YES
```
```
Input
3 66
15 21 22
Output
NO
```
```
Input
3 63
15 21 22
Output
YES
```


## Solution

[addemup.cpp](./addemup.cpp)

Solved!