# Sum of Odd Integers - 1100
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1327/A)  

You are given two integers `n` and `k`. Your task is to find if `n` can be represented as a sum of `k` `distinct positive odd` (not divisible by `2`) integers or not.  

You have to answer `t` independent test cases.  
  
### Input
The first line of the input contains one integer `t` (`1 <= t <= 10^5`) — the number of test cases.  

The next `t` lines describe test cases. The only line of the test case contains two integers `n` and `k` (`1 <= n, k <= 10^7`).  
  
### Output
For each test case, print the answer — "`YES`" (without quotes) if `n` can be represented as a sum of `k` `distinct positive odd` (not divisible by `2`) integers and "`NO`" otherwise.

### Examples
```
Input
6
3 1
4 2
10 3
10 2
16 4
16 5
Output
YES
YES
NO
YES
YES
NO
```

### Note
In the first test case, you can represent `3` as `3`.  

In the second test case, the only way to represent `4` is `1+3`.  

In the third test case, you cannot represent `10` as the sum of three distinct positive odd integers.  

In the fourth test case, you can represent `10` as `3+7`, for example.  

In the fifth test case, you can represent `16` as `1+3+5+7`.  

In the sixth test case, you cannot represent `16` as the sum of five distinct positive odd integers.

-----
## Solution

### Initial Thoughts
If the first number is odd, then the second must also be.  
Same for even.  
This is because odd+odd = even. So, odd+odd+odd != even.  
You can check if `k` is too large by using `sum of first k odd integers = k**2`. If the sum of the first `k` odd integers is greater than `n`, then it's impossible to solve.  

[sum_of_odd_integers.cpp](sum_of_odd_integers.cpp)  


Solved!