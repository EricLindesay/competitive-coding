# Sort Array By Parity
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/sort-array-by-parity)

### Description
Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.

Return ***any array** that satisfies this condition*.

### Input


- `1 <= nums.length <= 5000`
- `0 <= nums[i] <= 5000`




### Examples
```
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

```
Input: nums = [0]
Output: [0]
```


## Solution

Use two pointers.

[sort-array-by-parity.cpp](./sort-array-by-parity.cpp)

Solved!