# Plants vs Bad Guys
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/pvbg)

### Description

Oh no! There are a bunch of bad guys creeping around on Mikael’s lawn, and they all want to attack Mikael! Luckily, Mikael has planted several peashooters on his lawn that can protect him from the bad guys.
Mikael’s lawn consists of `N` rows, where Mikael has planted `R_ i` peashooters on row `i`. The peashooters only protect the row of the lawn where the peashooter is located, and each peashooter can protect the row from `1` bad guy every wave. The bad guys come in waves. During the first wave, there will be `1` bad guy on each row, during the second wave there will be `2` bad guys on each row, and at wave number `t`, there will be `t` bad guys on each row. Mikael will be attacked during a wave if the peashooters fail to protect any row from the naughty boys! In other words, if there is any row where there are more bad guys than there are peashooters, the bad guys will successfully reach Mikael (and maybe even eat him!!!).
How many waves of bad guys can Mikael’s peashooters protect him, before the bad guys manage to reach Mikael?

### Input
The first line consists of an integer `(1 <=slant N <=slant 10^6)`, the number of rows on Mikael’s lawn. The second line consists of `N` integers, where each integer `(1 <=slant R_ i <=slant 10^9)` represents the number of peashooters located at row `i`.

### Output
Print an integer `t` - the first wave that will successfully breach the peashooters’ defense and harm Mikael. In other words, the minimum value of `t` for which the bad guys can pass through the lawn.
Grading
Your solution will be tested on a number of test-case groups. To receive points for a group, your solution must correctly solve every test-case in the group. Group Point value Constraints `1` `10` `R_ i <=slant 9, N = 5` `2` `40` `R_ i <=slant 10^3, N <=slant 10^3` `3` `50` No further restrictions 

### Examples
```
Input
5
3 5 7 9 11
Output
4
```
```
Input
5
7 7 7 7 7
Output
8
```
```
Input
1
1
Output
2
```
```
Input
5
3 5 7 9 11
Output
4
```
```
Input
5
7 7 7 7 7
Output
8
```
```
Input
1
1
Output
2
```


## Solution

[pvbg/src/main.rs](./pvbg/src/main.rs)

Solved!