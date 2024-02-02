# Calculate Money in Leetcode Bank
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/calculate-money-in-leetcode-bank)

### Description
Hercy wants to save money for his first car. He puts money in the Leetcode bank **every day**.

He starts by putting in `$1` on Monday, the first day. Every day from Tuesday to Sunday, he will put in `$1` more than the day before. On every subsequent Monday, he will put in `$1` more than the **previous Monday**.<span style="display: none;"> </span>

Given `n`, return *the total amount of money he will have in the Leetcode bank at the end of the *`n^th`* day.*

### Input


- `1 <= n <= 1000`




### Examples
```
Input: n = 4
Output: 10
Explanation: After the 4^th day, the total is 1 + 2 + 3 + 4 = 10.
```

```
Input: n = 10
Output: 37
Explanation: After the 10^th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2^nd Monday, Hercy only puts in $2.
```

```
Input: n = 20
Output: 96
Explanation: After the 20^th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
```


## Solution

[calculate-money-in-leetcode-bank.cpp](./calculate-money-in-leetcode-bank.cpp)

Solved!