# Candy Distribution
- [Problem](#problem)
- [Solution](#candydistribution.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/candydistribution)

### Description

Kids like candy, so much that they start beating each other if the candy is not fairly distributed. So at your next party, you better start thinking before you buy the candy.
If there are `K` kids, you of course need `K \cdot X` candies for a fair distribution, where `X` is a positive natural number. But you learned that there is always one kid that loses one candy, so you better be prepared with exactly one spare candy, resulting in `(K \cdot X) + 1` candies.
Usually, the candies are packed into bags with a fixed number of candies `C` per bag. You will buy some of these bags so that the above constraints are fulfilled.

### Input
The first line gives the number of test cases `t` (`0 < t < 100`). Each test case is specified by two integers `K` and `C` on a single line, where `K` is the number of kids and `C` the number of candies in one bag (`1 <= K, C <= 10^9`). As your money is limited, you will never buy more than `10^9` candy bags.

### Output
For each test case, print one line. If there is no such number of candy bags to fulfill the above constraints, print “IMPOSSIBLE”. Otherwise print the number of candy bags you want to buy. If there is more than one solution, any will do. 

### Examples
```
Input
5
10 5
10 7
1337 23
123454321 42
999999937 142857133
Output
IMPOSSIBLE
3
872
14696943
166666655
```


## Solution

[candydistribution.cpp](./candydistribution.cpp)