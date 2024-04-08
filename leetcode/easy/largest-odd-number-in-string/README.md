# Largest Odd Number in String
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/largest-odd-number-in-string)

### Description
You are given a string `num`, representing a large integer. Return *the **largest-valued odd** integer (as a string) that is a **non-empty substring** of *`num`*, or an empty string *`""`* if no odd integer exists*.

A **substring** is a contiguous sequence of characters within a string.

### Input


- `1 <= num.length <= 10^5`
- `num` only consists of digits and does not contain any leading zeros.




### Examples
```
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
```

```
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
```

```
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
```


## Solution

[largest-odd-number-in-string.cpp](./largest-odd-number-in-string.cpp)

Solved!