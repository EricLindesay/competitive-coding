# Little Girl and Maximum Sum - 1500
**Tags**: Data Structures, Greedy, Implementation, Sorting
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/276/C)  

The little girl loves the problems on array queries very much.  

One day she came across a rather well-known problem: you've got an array of `n` elements (the elements of the array are indexed starting from 1); also, there are `q` queries, each one is defined by a pair of integers `l_i`, `r_i` `(1 <= l_i <= r_i <= n)`. You need to find for each query the sum of elements of the array with indexes from `l_i` to `r_i`, inclusive.  

The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.  
  
### Input
The first line contains two space-separated integers `n` (`1 <= n <= 2*10^5`) and `q` (`1 <= q <= 2*10^5`) — the number of elements in the array and the number of queries, correspondingly.  

The next line contains `n` space-separated integers `a_i` (`1 <= a_i <= 2*10^5`) — the array elements.  

Each of the following `q` lines contains two space-separated integers `l_i` and `r_i` (`1 <= l_i <= r_i <= n`) — the `i`-th query.  
  
### Output
In a single line print, a single integer — the maximum sum of query replies after the array elements are reordered.  

Please, do not use the `%lld` specifier to read or write 64-bit integers in C++. It is preferred to use the `cin`, `cout` streams or the `%I64d` specifier.  

### Examples
```
Input
3 3
5 3 2
1 2
2 3
1 3
Output
25
```
```
Input
5 3
5 2 4 1 3
1 5
2 3
2 3
Output
33
```


## Solution

### Initial Thoughts
Create a counter for how many times each array element would be seen in the query.  
Then, sort the list and the counter, then just multiply each element respectively (like a zip).  
E.g.
```
arr = [5, 1, 3]
ranges = 1-2
         2-3

counter = [1, 2, 2]
sorted_arr = [1, 3, 5]
sorted_counter = [1, 2, 2]

ans = 1*1 + 3*2 + 5*2
```

Data Structures  
The array storing the input (nums) should be stored as a forward_list. This is because nums exists only to be sorted and looped though forward. You don't need to be able to access any value (except when looping through it forwards) but you do need to sort it which involves a lot of insertion. Because of this, a forward_list is best for it.  
The array storing the queries needs to be sorted and to have any value access it in constant time.  

To create the array containing how much each value is seen in the range, I used this [stackoverflow link](https://stackoverflow.com/questions/18408659/how-to-increment-all-values-in-an-array-interval-by-a-given-amount).  

Current attempt:  
[counter.cpp](solutions/counter.cpp)  
This is too slow for larger inputs, it fails at 200k inputs (the upper bound of inputs). I'm 90% sure this is due to how I sort the queries, this takes O(nlogn) time, which is just too slow.  