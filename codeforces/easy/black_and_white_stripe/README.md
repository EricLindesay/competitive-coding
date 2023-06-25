# Black and White Stripe - 1000
**Tags**: Implementation, Two Pointers  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1690/D)  

You have a stripe of checkered paper of length `n`. Each cell is either white or black.  

What is the minimum number of cells that must be recolored from white to black in order to have a segment of `k` consecutive black cells on the stripe?  

If the input data is such that a segment of `k` consecutive black cells already exists, then print `0`.   
  
### Input
The first line contains an integer `t` (`1 <= t <= 10^4`) — the number of test cases.  

Next, descriptions of `t` test cases follow.  

The first line of the input contains two integers `n` and `k` ('`W`' (white) and '`B`' (black). The line length is `n`).  

It is guaranteed that the sum of values `n` does not exceed `2*10^5`.  
  
### Output
For each of `t` test cases print an integer — the minimum number of cells that need to be repainted from white to black in order to have a segment of `k` consecutive black cells.

### Examples
```
Input
4
5 3
BBWBW
5 5
BBWBW
5 1
BBWBW
1 1
W
Output
1
2
0
1
```

### Note
In the first test case, `s`="`BBWBW`" and `k=3`. It is enough to recolor `s_3` and get `s`="`BBBBW`". This string contains a segment of length `k=3` consisting of the letters '`B`'.  

In the second test case of the example `s`="`BBWBW`" and `k=5`. It is enough to recolor `s_3` and `s_5` and get `s`="`BBBBB`". This string contains a segment of length `k=5` consisting of the letters '`B`'.  

In the third test case of the example `s`="`BBWBW`" and `k=1`. The string `s` already contains a segment of length `k=1` consisting of the letters '`B`'.


## Solution

### Initial Thoughts
Find all substrings of length k and count how many black pieces there are. The number you need to change is then k-most_blacks, where most_blacks is the sum of the substring contianing the most blacks.  
This would be O(2n) if done best.  
You can shrink this to O(n) by doing it as you parse the data.  
```
5 3
BBWBW

BBW  = 2 blacks, 1 change
BWB  = 2 blacks, 1 change
WBW  = 1 black, 2 changes

print(1)
```

[black_and_white_stripe.cpp](black_and_white_stripe.cpp)  

Solved!  
