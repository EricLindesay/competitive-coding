# Count Nice Pairs in an Array
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/count-nice-pairs-in-an-array)

### Description
You are given an array `nums` that consists of non-negative integers. Let us define `rev(x)` as the reverse of the non-negative integer `x`. For example, `rev(123) = 321`, and `rev(120) = 21`. A pair of indices `(i, j)` is **nice** if it satisfies all of the following conditions:


	- `0 <= i < j < nums.length`
	- `nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])`


Return *the number of nice pairs of indices*. Since that number can be too large, return it **modulo** `10^9 + 7`.

### Input


- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`




### Examples
```
Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
```

```
Input: nums = [13,10,35,24,76]
Output: 4
```


## Solution

### Naive Solution
Just reverse each number in the array and store this in a new array.  
Then you can loop over in O(n^2) using `nums` and the reversed nums (`revs`) and see which satisfy the conditions.

[squared-solution.cpp](./squared-solution.cpp)

### O(n) solution
We get told that it has to satisfy `nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])`.
This can be rearranged as
`nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])`
Or as
`(nums[i] - rev(nums[i])) - (nums[j] - rev(nums[j])) == 0`

Then it just becomes a two-sum problem. Find two numbers which add/subtract together to equal 0.

[count-nice-pairs-in-an-array.cpp](./count-nice-pairs-in-an-array.cpp)

Solved!