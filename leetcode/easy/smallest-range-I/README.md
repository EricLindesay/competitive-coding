# smallest-range-I
- [Problem](#problem)
- [Solution](#smallest-range-I.cpp)

## Problem
[Problem link](https://leetcode.com/problems/smallest-range-i/)

### Description
You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

### Input
You are given an integer array nums and an integer k.

### Output
Return the minimum score of nums after applying the mentioned operation at most once for each index in it

### Examples
```
Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
```

```
Input: nums = [0,10], k = 2
Output: 6
Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
```

```
Input: nums = [1,3,6], k = 3
Output: 0
Explanation: Change nums to be [4, 4, 4]. The score is max(nums) - min(nums) = 4 - 4 = 0.
```

## Solution

I'm quite embarrassed, my initial thoughts for this problem were correct but I got in my own head and convinced myself it was incorrect. My problem was that I convinced myself that all the numbers (other than min and max) which are within k of the min and max are important, but they aren't because you can always just increase them to a better value using k. I started thinking that you could only change two values using k, not all of them.

### Incorrect
Find as many values which satisfy this condition:
- The difference between this value and the smallest value is at most k.

Then find as many values which satisfy this condition:
- The difference between this value and the largest value is at most k.

If there is overlap between the two arrays, return 0.
Otherwise, return the difference between smallest + k and largest - k

[incorrect.cpp](incorrect.cpp)

### Correct
Just find the difference between the minimum and maximum value.  
Then subtract `2*k` from this difference. The value to return is that value and if that value is negative, instead return 0.

[smallest-range-I.cpp](./smallest-range-I.cpp)

Solved!