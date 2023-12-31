# #include<scoring>
- [Problem](#problem)
- [Solution](#includescoring.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/includescoring)

### Description
As you may know, LTH Challenge is part of a series of seven competitions called the Swedish Coding Cup. Each contest in the series gives the contestants a number of points depending on how well they place in the contest.

After each contest, scores are assigned according to the following table:
| Rank | Score | Rank | Score |
|------|-------|------|-------|
| `1`  | `100` | `16` | `15`  |
| `2`  | `75`  | `17` | `14`  |
| `3`  | `60`  | `18` | `13`  |
| `4`  | `50`  | `19` | `12`  |
| `5`  | `45`  | `20` | `11`  |
| `6`  | `40`  | `21` | `10`  |
| `7`  | `36`  | `22` | `9`   |
| `8`  | `32`  | `23` | `8`   |
| `9`  | `29`  | `24` | `7`   |
| `10` | `26`  | `25` | `6`   |
| `11` | `24`  | `26` | `5`   |
| `12` | `22`  | `27` | `4`   |
| `13` | `20`  | `28` | `3`   |
| `14` | `18`  | `29` | `2`   |
| `15` | `16`  | `30` | `1`   |
If two or more contestants get the same rank in the contest, they are instead assigned the average score of all the corresponding ranks. This score is always rounded up to the closest integer. For example, if three contestants share the second place they all recieve `ceil((75 + 60 + 50)/(3)) = 62` points.

Contestants may participate in every contest either on-site or online. If they compete on-site, they get one extra point, no matter their original score. If a contestant does not participate in a contest, they are assigned a score of `0`.

At LTH Challenge, the rank of each contestant is computed using what is called ACM scoring. Each contestant is ranked first on the number of problems they solve (in descending order), secondly on their time penalty (in ascending order) and finally the time at which they submitted their last accepted solution in minutes (in ascending order). If all these three properties are equal, the contestants are tied.

As you may understand, it is really tedious to compute the scores of all the contestants after such a contest. The jury does not really want to program this themselves; they prefer to just use some existing library instead. However, it turns out that since this is the first time the Swedish Coding Cup is held, nobody had written such a library!
Fortunately, they have you.

### Input
The input consists of:
- one line with the integer `n` (`1 <= n <= 1, 000`), the number of contestants.
- `n` lines with the integers `s`,`p`, `f` and `o`, (`0 <= s <= 9`, `0 <= p <= 10^9`, `0 <= f <= 300`, `0 <= o <= 1`) - the number of problems solved by a contestant, the time penalty of the contestant, the time at which they submitted their last accepted solution and the number of extra points the contestant should get due to competing on-site.

### Output
Output `n` lines containing the scores of all the contestants in the order they were listed in the input.

### Examples
```
Input
41
6 179 65 1
6 305 86 1
6 324 96 0
6 390 112 1
5 280 97 0
4 79 45 1
4 94 49 1
4 126 55 1
4 160 100 1
4 173 76 0
4 214 106 1
4 221 110 1
4 226 96 1
4 384 103 0
3 35 26 1
3 90 56 0
3 113 83 1
3 137 106 0
3 171 101 1
3 184 104 0
3 195 65 1
2 14 11 1
2 15 10 1
2 17 11 1
2 19 12 1
2 20 13 1
2 21 14 0
2 29 20 1
2 30 19 0
2 36 27 1
2 39 13 1
2 52 23 1
2 52 31 1
2 69 23 1
2 86 17 0
2 113 55 1
2 125 62 1
2 328 119 0
1 10 10 0
1 15 15 1
1 33 33 0
Output
101
76
60
51
45
41
37
33
30
26
25
23
21
18
17
15
15
13
13
11
11
10
9
8
7
6
4
4
2
2
1
1
1
1
0
1
1
0
0
1
0
```


## Solution

[includescoring.cpp](./includescoring.cpp)