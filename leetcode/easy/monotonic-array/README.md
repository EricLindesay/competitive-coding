# Monotonic Array
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/monotonic-array)

### Description
An array is **monotonic** if it is either monotone increasing or monotone decreasing.

An array `nums` is monotone increasing if for all `i <= j`, `nums[i] <= nums[j]`. An array `nums` is monotone decreasing if for all `i <= j`, `nums[i] >= nums[j]`.

Given an integer array `nums`, return `true`* if the given array is monotonic, or *`false`* otherwise*.

### Input


- `1 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`




### Examples
```
Input: nums = [1,2,2,3]
Output: true
```

```
Input: nums = [6,5,4,4]
Output: true
```

```
Input: nums = [1,3,2]
Output: false
```


## Solution

[monotonic-array.cpp](./monotonic-array.cpp)
