# Minimum Number of Flips to Make the Binary String Alternating
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating)

### Description
You are given a binary string `s`. You are allowed to perform two types of operations on the string in any sequence:


	- **Type-1: Remove** the character at the start of the string `s` and **append** it to the end of the string.
	- **Type-2: Pick** any character in `s` and **flip** its value, i.e., if its value is `'0'` it becomes `'1'` and vice-versa.


Return *the **minimum** number of **type-2** operations you need to perform* *such that *`s` *becomes **alternating**.*

The string is called **alternating** if no two adjacent characters are equal.


	- For example, the strings `"010"` and `"1010"` are alternating, while the string `"0100"` is not.


### Input


- `1 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.




### Examples
```
Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
```

```
Input: s = "010"
Output: 0
Explanation: The string is already alternating.
```

```
Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
```


## Solution

Surely you just find how many are already in position and then just return how many aren't?  
You would also need to keep into account
`110` which goes to `101` with one type-1 operation, resulting in 0 type 2. But this separation can only happen if there are two adjacent.  

[minimum-number-of-flips-to-make-the-binary-string-alternating.cpp](./minimum-number-of-flips-to-make-the-binary-string-alternating.cpp)
