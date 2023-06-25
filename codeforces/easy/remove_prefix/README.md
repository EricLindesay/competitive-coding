# Remove Prefix - 800
**Tags**: Data Structures, Implementation  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1714/B)  

Polycarp was presented with some sequence of integers `a` of length `n` (`1 `different` numbers (i.e. distinct numbers).  

In order to make his sequence like this, Polycarp is going to make some (possibly zero) number of moves.  

In one move, he can:   

 - remove the first (leftmost) element of the sequence. 
For example, in one move, the sequence `[3, 1, 4, 3]` will produce the sequence `[1, 4, 3]`, which consists of different numbers.  

Determine the minimum number of moves he needs to make so that in the remaining sequence all elements are different. In other words, find the length of the smallest prefix of the given sequence `a`, after removing which all values in the sequence will be unique.  
  
### Input
The first line of the input contains a single integer `t` (`1 <= t <= 10^4`) — the number of test cases.  

Each test case consists of two lines.  

The first line contains an integer `n` (`1 <= n <= 2 * 10^5`) — the length of the given sequence `a`.  

The second line contains `n` integers `a_1, a_2, ..., a_n` (`1 <= a_i <= n`) — elements of the given sequence `a`.  

It is guaranteed that the sum of `n` values over all test cases does not exceed `2 * 10^5`.  
  
### Output
For each test case print your answer on a separate line — the minimum number of elements that must be removed from the beginning of the sequence so that all remaining elements are different.

### Examples
```
Input
5
4
3 1 4 3
5
1 1 1 1 1
1
1
6
6 5 4 3 2 1
7
1 2 1 7 1 2 1
Output
1
4
0
0
5
```

### Note
The following are the sequences that will remain after the removal of prefixes:  

 - `[1, 4, 3]`; 
- `[1]`; 
- `[1]`; 
- `[6, 5, 4, 3, 2, 1]`; 
- `[2, 1]`. 
It is easy to see that all the remaining sequences contain only distinct elements. In each test case, the shortest matching prefix was removed.


-----
## Solution

### Initial Thoughts
Sort it. Then you can easily find repeats in nlogn + n time.  
Then you know which ones repeat, loop backwards through the list until you find two occurences of those that repeat.  
[remove_prefix.cpp](./remove_prefix.cpp)

Solved!