# Omkar and Baseball - 1500

- [Problem](#problem)
- [Solution](#solution)


## Problem
[Problem Link](https://codeforces.com/problemset/problem/1372/C)  

Patrick likes to play baseball, but sometimes he will spend so many hours hitting home runs that his mind starts to get foggy! Patrick is sure that his scores across `n` sessions follow the identity permutation (ie. in the first game he scores `1` point, in the second game he scores `2` points and so on). However, when he checks back to his record, he sees that all the numbers are mixed up!   

Define a special exchange as the following: choose any subarray of the scores and permute elements such that no element of subarray gets to the same position as it was before the exchange. For example, performing a special exchange on `[1,2,3]` can yield `[3,1,2]` but it cannot yield `[3,2,1]` since the `2` is in the same position.   

Given a permutation of `n` integers, please help Patrick find the minimum number of special exchanges needed to make the permutation sorted! It can be proved that under given constraints this number doesn't exceed `10^{18}`.  

An array `a` is a subarray of an array `b` if `a` can be obtained from `b` by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.  
  
### Input
Each test contains multiple test cases. The first line contains the number of test cases `t` (`1 <= t <= 100`). Description of the test cases follows.  

The first line of each test case contains integer `n` (`1 <= n <= 2 \cdot 10^5`)  — the length of the given permutation.  

The second line of each test case contains `n` integers `a_{1},a_{2},...,a_{n}` (`1 <= a_{i} <= n`)  — the initial permutation.  

It is guaranteed that the sum of `n` over all test cases does not exceed `2 * 10^5`.  
  
### Output
For each test case, output one integer: the minimum number of special exchanges needed to sort the permutation.

### Examples
```
Input
2
5
1 2 3 4 5
7
3 2 4 5 1 6 7
Output
0
2
```
### Note
In the first permutation, it is already sorted so no exchanges are needed.  

It can be shown that you need at least `2` exchanges to sort the second permutation.  

`[3, 2, 4, 5, 1, 6, 7]`  

Perform special exchange on range (`1, 5`)  

`[4, 1, 2, 3, 5, 6, 7]`  

Perform special exchange on range (`1, 4`)  

`[1, 2, 3, 4, 5, 6, 7]`


## Solution

### Initial Thoughts
Is it already sorted? Yes, return 0.  
Is there one thing which is in the sorted position? Yes, return 2.  
Is it not sorted and nothing is in the right position? Yes, return 1.
Could try and sort it, either forward or in reverse or both.  
Then essentially do a bubble sort. The right most value is the correct place. Then in the left sublist, find how many are in the right position and repeat.  
That would take way too long though.  
What if we just assume the values will only be 0, 1 or 2.  

[omkar_and_baseball.cpp](omkar_and_baseball.cpp)

The reasons I failed twice before it succeeded:
1. I didn't have the return 1 in my notes at that point so I forgot to add it.  
2. Didn't test for extremeties like if n = 1 or n = 2.  

Solved!