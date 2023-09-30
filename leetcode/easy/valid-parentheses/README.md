# Valid Parentheses
- [Problem](#problem)
- [Solution](#valid-parentheses.cpp)

## Problem
[Problem link](problem_link)

### Description
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

<ol>
	- Open brackets must be closed by the same type of brackets.
	- Open brackets must be closed in the correct order.
	- Every close bracket has a corresponding open bracket of the same type.
</ol>

### Input


- `1 <= s.length <= 10^4`
- `s` consists of parentheses only `'()[]{}'`.




### Examples
```
Input: s = "()"
Output: true
```

```
Input: s = "()[]{}"
Output: true
```

```
Input: s = "(]"
Output: false
```


## Solution

[valid-parentheses.cpp](./valid-parentheses.cpp)

Solved!