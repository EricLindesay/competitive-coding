# Add Modulo 10 - 1400
**Tags**: Maths, Number Theory  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1714/E)  

You are given an array of `n` integers `a_1, a_2, ..., a_n`  

You can apply the following operation an arbitrary number of times:   

 - select an index `i` (`1 <= i <= n`) and replace the value of the element `a_i` with the value `a_i + (a_i \bmod 10)`, where `a_i \bmod 10` is the remainder of the integer dividing `a_i` by `10`. 
For a single index (value `i`), this operation can be applied multiple times. If the operation is applied repeatedly to the same index, then the current value of `a_i` is taken into account each time. For example, if `a_i=47` then after the first operation we get `a_i=47+7=54`, and after the second operation we get `a_i=54+4=58`.  

Check if it is possible to make `all` array elements equal by applying multiple (possibly zero) operations.  

For example, you have an array `[6, 11]`.   

 - Let's apply this operation to the first element of the array. Let's replace `a_1 = 6` with `a_1 + (a_1 \bmod 10) = 6 + (6 \bmod 10) = 6 + 6 = 12`. We get the array `[12, 11]`. 
- Then apply this operation to the second element of the array. Let's replace `a_2 = 11` with `a_2 + (a_2 \bmod 10) = 11 + (11 \bmod 10) = 11 + 1 = 12`. We get the array `[12, 12]`. 
Thus, by applying `2` operations, you can make all elements of an array equal.  
  
### Input
The first line contains one integer `t` (`1 <= t <= 10^4`) — the number of test cases. What follows is a description of each test case.  

The first line of each test case contains one integer `n` (`1 <= n <= 2 * 10^5`) — the size of the array.  

The second line of each test case contains `n` integers `a_i` (`0 <= a_i <= 10^9`) — array elements.  

It is guaranteed that the sum of `n` over all test cases does not exceed `2 * 10^5`.  
  
### Output
For each test case print:  

 - `YES` if it is possible to make all array elements equal; 
- `NO` otherwise. 
You can print `YES` and `NO` in any case (for example, the strings `yEs`, `yes`, `Yes` and `YES` will be recognized as a positive answer) .

### Examples
```
Input
10
2
6 11
3
2 18 22
5
5 10 5 10 5
4
1 2 4 8
2
4 5
3
93 96 102
2
40 6
2
50 30
2
22 44
2
1 5
Output
Yes
No
Yes
Yes
No
Yes
No
No
Yes
No
```

### Note
The first test case is clarified above.  

In the second test case, it is impossible to make all array elements equal.  

In the third test case, you need to apply this operation once to all elements equal to `5`.  

In the fourth test case, you need to apply this operation to all elements until they become equal to `8`.  

In the fifth test case, it is impossible to make all array elements equal.  

In the sixth test case, you need to apply this operation to all elements until they become equal to `102`.


-----
## Solution

### Initial Thoughts
The numbers all form a cycle. Unless it starts with 5 or 0.  
```
1 [2 4 8 6...]
2 [4 8 6 2...]
3 [6 2 4 8...] 
4 [8 6 2 4...]

5 [0 5 0 5]

6 [2 4 8 6]
7 [4 8 6 2]
8 [6 2 4 8]
9 [8 6 2 4]

0 [0...]
```
If any of the numbers have a 5 or 0. If any of the other numbers DO NOT have a 5 or 0, the answer is NO.  
If there is a zero which is lower than a 5, it's impossible.  
0s and 5s can easily be taken care of.  

### Always Lower
What if we try to always do the operation in the lower number.  
This doesn't work on numbers like `2 18 22` because it will just form an infinite loop.  
So arbitrarily set the condition that only loop until the lowest number is less than the original highest + 40.  
This didn't work but mainly because at this point, the 0 5 condition was incorrect.  
[always_lower.cpp](./always_lower.cpp)  

### Modulo 20
Well since the numbers loop every 20, just modulo 20 each number.  
And then make sure that each number convert into the same.  
We can check this by setting them to the first number above 20. If they are valid, the first number above 20 would be the same for all of them.  
Otherwise, they are not valid.  
[mod20.cpp](./mod20.cpp)

