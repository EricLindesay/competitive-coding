# Is Subsequence
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/is-subsequence)

### Description
Given two strings `s` and `t`, return `true`* if *`s`* is a **subsequence** of *`t`*, or *`false`* otherwise*.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"**a**b**c**d**e**"` while `"aec"` is not).
## Notes
**Follow up:** Suppose there are lots of incoming `s`, say `s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub>` where `k >= 10^9`, and you want to check one by one to see if `t` has its subsequence. In this scenario, how would you change your code?

### Input


- `0 <= s.length <= 100`
- `0 <= t.length <= 10^4`
- `s` and `t` consist only of lowercase English letters.




### Examples
```
Input: s = "abc", t = "ahbgdc"
Output: true
```
```
Input: s = "axc", t = "ahbgdc"
Output: false
```


## Solution

O(n) time
O(1) space

Go through `t` character by character. If the current char matches the latest un-seen character in `s`, increment the `s` pointer.

[is-subsequence.cpp](./is-subsequence.cpp)

Solved!