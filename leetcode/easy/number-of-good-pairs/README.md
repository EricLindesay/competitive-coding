# Number of Good Pairs
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/number-of-good-pairs)

### Description
Given an array of integers `nums`, return *the number of **good pairs***.

A pair `(i, j)` is called *good* if `nums[i] == nums[j]` and `i` < `j`.

### Input


- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`




### Examples
```
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
```

```
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
```

```
Input: nums = [1,2,3]
Output: 0
```


## Solution
Just count how many of each number you have seen. If you find a element you have already seen, increase the count by how many times you have seen it.

[number-of-good-pairs.cpp](./number-of-good-pairs.cpp)

Solved!