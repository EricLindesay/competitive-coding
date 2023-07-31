# rudolf-and-the-another-competition
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://codeforces.com/contest/1846/problem/C#)

### Description
Rudolf has registered for a programming competition that will follow the rules of ICPC. The rules imply that for each solved problem, a participant gets 1 point, and also incurs a penalty equal to the number of minutes passed from the beginning of the competition to the moment of solving the problem. In the final table, the participant with the most points is ranked higher, and in case of a tie in points, the participant with the lower penalty is ranked higher.

In total, `n` participants have registered for the competition. Rudolf is a participant with index 1. It is known that m problems will be proposed. And the competition will last `h` minutes.

A powerful artificial intelligence has predicted the values `t_{i,j}`, which represent the number of minutes it will take for the `i`-th participant to solve the `j`-th problem.

Rudolf realized that the order of solving problems will affect the final result. For example, if `h = 120`, and the times to solve problems are `[20,15,110]`, then if Rudolf solves the problems in the order:
- `3,1,2`, then he will only solve the third problem and get `1` point and `110` penalty.
- `1,2,3`, then he will solve the first problem after `20` minutes from the start, the second one after `20+15=35` minutes, and he will not have time to solve the third one. Thus, he will get `2` points and `20+35=55` penalty.
- `2,1,3`, then he will solve the second problem after `15` minutes from the start, the first one after `15+20=35` minutes, and he will not have time to solve the third one. Thus, he will get `2` points and `15+35=50` penalty. 

Rudolf became interested in what place he will take in the competition if each participant solves problems in the optimal order based on the predictions of the artificial intelligence. It will be assumed that in case of a tie in points and penalty, Rudolf will take the best place.

### Input
The first line contains an integer `t (1 ≤ t ≤ 10^3)` — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains three integers `n`, `m`, `h` `(1 ≤ n ⋅ m ≤ 2 ⋅ 10^5, 1 ≤ h ≤ 10^6)` — the number of participants, the number of problems, and the duration of the competition, respectively.

Then there are `n` lines, each containing `m` integers `t_{i,j}` `(1 ≤ t_{i,j} ≤ 10^6)` — the number of minutes it will take for the `i`-th participant to solve the `j`-th problem.

The sum of `n⋅m` over all test cases does not exceed `2⋅10^5`.

### Output
For each test case, output an integer — Rudolf's place in the final table if all participants solve problems in the optimal order.

### Examples
```
Input
5
3 3 120
20 15 110
90 90 100
40 40 40
2 1 120
30
30
1 3 120
10 20 30
3 2 27
8 9
10 7
10 8
3 3 15
7 2 6
7 5 4
1 9 8
Output
2
1
1
2
1
```

## Solution

For this one, read in the input and then sort it (this would have been better as a priority queue but I didn't think of that).  
If its the first user its Rudolf, so store that separately.
Then, for every other user, if the user has more points than rudolf then rudolf moves down a place.  
If a user has equal points but less penalty, rudolf moves down a place.  

[rudolf-and-the-another-competition.cpp](rudolf-and-the-another-competition.cpp)

Solevd! within competition
Intentionally misspelt the Solevd line since it got hacked

However, it got hacked! Shock! Horror!