# Alien Math
- [Problem](#problem)
- [Solution](#alienmath.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/alienmath)

### Description

Humans are exploring the stars, and we have encountered aliens! In an exchange of scientific knowledge, we’ve learned that not only do they use entirely different symbols to do math, they don’t even use base ten! It would be nice to have a program to convert the alien numbers to decimal.
Shockingly, the aliens represent each of their digits with what might be multiple ascii characters. For example, aba might be a single digit for the alien’s numerical system.
Given the base of their number system, an ordered list of all their system’s digits, and a number `X`, convert `X` to base `10` and print it without any leading zeros.
For a quick refresher on number systems, a number system with base `B` has `B` digits that represent the values `0` through `B-1`. For example, an alien number system with base `3` could have digits zork, ooble, and trzap representing the values `0`, `1`, and `2` respectively. The alien number trzapzorkooble, when written in standard decimal notation, is just `2 \cdot 3^2 + 0 \cdot 3^1 + 1 \cdot 3^0 = 19`.

### Input
The first line of input will consist of a single integer `B` (`2 <= B <= 10^3`) indicating the number of digits used in the alien number system.
The next line consists of `B` strings `D_0, D_1, ... , D_{B-1}` with a single space between each string. These represent the digits in the alien number system, namely string `D_ i` is the digit with value `i`. Each digit string `D_ i` will consist of at least one and at most `10` characters and will only contain lowercase letters (i.e. a through z).
The third line contains a single string `X` consisting of at least `1` and at most `300` characters. This string represents a number written in the alien number system. The value of this number, in decimal, is at most `10^9`. It may be written with leading zeros in the alien number system. You are guaranteed that `X` is the concatenation of digits from the alien number system (i.e. it is a valid number in their system).
Oh, and this is important. The aliens knew their system was a bit complicated, so to make it easier to read, they designed their number system so that the strings representing distinct digits do not have one being a prefix of the other. That is, `D_ i` is not a prefix of `D_ j` for any indices `i !=q j`.

### Output
Print the value of `X` in standard base `10` notation without any leading zeros. 

### Examples
```
Input
2
ab aab
aababaab
Output
5
```
```
Input
10
a b c d e f g h i j
ighfdaj
Output
8675309
```
```
Input
2
zero one
zerozerozero
Output
0
```
```
Input
2
zero one
zeroonezero
Output
2
```
```
Input
3
zork ooble trzap
trzapzorkooble
Output
19
```


## Solution
Have a map which maps a string to the value it represents. This is so you can have `log(n)` lookup for the strings to value.  

Then, loop through the current word, keeping track of characters seen since the last valid number. If this string is a valid number in their maths language, multiply result by the base and increment the value and then reset the characters you are keeping track of.  

[alienmath.cpp](./alienmath.cpp)

Solved!