# Directional Increase - 1300
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1693/A)  

We have an array of length `n`. Initially, each element is equal to `0` and there is a pointer located on the first element.  

We can do the following two kinds of operations any number of times (possibly zero) in any order:  

- If the pointer is not on the last element, increase the element the pointer is currently on by `1`. Then move it to the next element.
- If the pointer is not on the first element, decrease the element the pointer is currently on by `1`. Then move it to the previous element.
But there is one additional rule. `After we are done, the pointer has to be on the first element.`  

You are given an array `a`. Determine whether it's possible to obtain `a` after some operations or not.  
  
### Input
The first line contains a single integer `t` `(1<= t<= 1000)`  — the number of test cases. The description of the test cases follows.  

The first line of each test case contains a single integer `n` `(1<= n<= 2 * 10^5)`  — the size of array `a`.  

The second line of each test case contains `n` integers `a_1, a_2, ..., a_n` (`-10^9 <= a_i <= 10^9`) — elements of the array.  

It is guaranteed that the sum of `n` over all test cases doesn't exceed `2 * 10^5`.  
  
### Output
For each test case, print "Yes" (without quotes) if it's possible to obtain `a` after some operations, and "No" (without quotes) otherwise.  

You can output "Yes" and "No" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

### Examples
```
Input
7
2
1 0
4
2 -1 -1 0
4
1 -4 3 0
4
1 -1 1 -1
5
1 2 3 4 -10
7
2 -1 1 -2 0 0 0
1
0
Output
No
Yes
No
No
Yes
Yes
Yes
```

### Note
In the first test case we can obtain the array after some operations, but the pointer won't be on the first element.  

One way of obtaining the array in the second test case is shown below.  

<ins>0</ins>, 0, 0, 0  
1, <ins>0</ins>, 0, 0  
<ins>1</ins>, -1, 0, 0  
2, <ins>-1</ins>, 0, 0  
2, 0, <ins>0</ins>, 0  
2, <ins>0</ins>, -1, 0  
<ins>2</ins>, -1, -1, 0  

## Solution

### Initial Thoughts
One thing I noticed is that the sum of the array must be 0.  
The left most element cannot be negative.  
The right most non-zero element must be negative (excluding the first element).  
If the first element is one, then the remaining sublist must also follow this pattern.  
