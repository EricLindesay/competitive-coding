# Birthday Memorization
- [Problem](#problem)
- [Solution](#fodelsedagsmemorisering.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/fodelsedagsmemorisering)

### Description

Krarkl wants to learn the birthdays of all his `N` friends, so he knows whom to congratulate each day. Unfortunately collisions sometimes arise, meaning several friends may have the same birthday. This may confuse Krarkl, so he decided to only remember the birthday of the friend he likes the most in case of a collision. Given a list of birthdays for each of his friends and how much Krarkl likes each friend, print what friends Krarkl will remember the birthday for.

### Input
The first line of input contains an integer `N` (`1 <= N <= 2, 000`), the number of friends.
Then `N` lines follow, one for each friend. The `i`’th of these lines contains a string with the `i`’th friend’s first name `S_ i` (`S_ i` will be between `1` and `10` letters long), an integer `C_ i` (`0 <= C_ i <= 100, 000`) denoting how much Krarkl likes the friend, and their birthday given in the format DD/MM (where DD is a day between 01 and 31, and MM is a month between 01 and 12). A higher value of `C_ i` means that Krarkl likes that friend more.
The birthdays will be real dates during 2020 (a leap year), for example 28/02 for February 28. All names will consist only of small English letters (a-z) with a capital first letter (A-Z). All `C_ i` will be distinct.

### Output
On the first line, print an integer `K` – the number of friends whose birthdays Krarkl will remember.
This should be followed by `K` lines containing a single word each, the first names of the chosen friends, in lexicographical order.

### Scoring
Your solution will be tested on a number of test case groups. To get the points for a group, you need to pass all test cases in the group. Group Points Constraints `1` `30` `N <= 100` `2` `70` No further constraints Explanation of samples
In the first sample, Sanna and Simon have the same birthday. Since Krarkl likes Sanna less than Simon (`1 < 2`), Krarkl will only remember Simon’s and Saga’s birthdays.
In the second sample, Krarkl has really bad luck and will miss half of his friends’ birthdays. 

### Examples
```
Input
3
Sanna 1 16/03
Simon 2 16/03
Saga 3 14/10
Output
2
Saga
Simon
```
```
Input
10
Oden 78 03/12
Tor 132 14/05
Freja 10000 14/05
Loke 512 12/10
Hel 14 04/05
Fjorgynn 532 13/05
Hildegun 500 13/05
Vindsval 17 03/12
Snotra 20 04/05
Kvaser 420 03/12
Output
5
Fjorgynn
Freja
Kvaser
Loke
Snotra
```


## Solution

[fodelsedagsmemorisering.cpp](./fodelsedagsmemorisering.cpp)

Solved!