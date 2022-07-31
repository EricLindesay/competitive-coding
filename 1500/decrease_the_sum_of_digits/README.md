# Decrease the Sum of Digits - 1500
**Tags**: Greedy, Maths  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1409/D)  

You are given a positive integer `n`. In one move, you can increase `n` by one (i.e. make `n := n + 1`). Your task is to find the minimum number of moves you need to perform in order to make the sum of digits of `n` be less than or equal to `s`.  

You have to answer `t` independent test cases.  
  
### Input
The first line of the input contains one integer `t` (`1 <= t <= 2 * 10^4`) — the number of test cases. Then `t` test cases follow.  

The only line of the test case contains two integers `n` and `s` (`1 <= n <= 10^{18}`; `1 <= s <= 162`).  
  
### Output
For each test case, print the answer: the minimum number of moves you need to perform in order to make the sum of digits of `n` be less than or equal to `s`.

### Examples
```
Input
5
2 1
1 1
500 4
217871987498122 10
100000000000000001 1
Output
8
0
500
2128012501878
899999999999999999
```


-----
## Solution

### Initial Thoughts
You first should find the sum of the digits of n.  
Do a while loop, for while the sum of the digits is less than s.  
Then, go through each digit, starting from the least significant.  
For that digit, increase n and the number of moves by the appropriate multiple of ten minus the digit.  
E.g.
```
n = 182   s = 2
sum = 11
LSD = 2

n += 10-2
n = 190
sum = 10
LSD = 9

n += 10**(10-9)
n = 200

sum = 2, that meets the target so stop
```
I am not certain whether this would have been fast enough as I never tested it, however my other method is more efficient anyway so it doesn't matter.  
[decrease_the_sum_of_digits.cpp](./decrease_the_sum_of_digits.cpp)  

### No Recalculation
I noticed with the previous method, it recalculates the sum of digits every time.  
This does not need to be done, you can just keep track of how the digits change and then you can just change the total as needed.  
This gets more complicated. For example, when its 191, would go to 200 after the first loop so you would decrease the sum by 10 rather than just 1.  
To fix this, you have a "look ahead" loop.  
When the next digit is 9, this loop activates. Then it calculates how the sum of digits should change and changes it. You also know that these numbers will become zero, so you can also increment the digits counter.  
[look_forward.cpp](./look_forward.cpp)  

Solved!  
