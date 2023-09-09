# Product of Array Except Self
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/product-of-array-except-self/)

### Description
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

### Examples
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```
```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

## Solution

### Initial Thought
Find the product of the array.  
Loop through each element and divide it by the element's value.  
Return those values as an array.  

However, it specifies you aren't allowed to use the division operator.

Instead:
- Create a vector filled with 1.
- Loop through each number, everytime you loop through a number, multiply each element (except that index) in the output vector by that value.  

This is constant space complexity (since you don't count the output as extra space). But O(n^2) time complexity. This time complexity might be able to be reduced by using stl functions.

[product-of-array-except-self.cpp](./product-of-array-except-self.cpp)