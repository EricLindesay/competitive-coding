# sort-characters-by-frequency
- [Problem](#problem)
- [Solution](#sort-characters-by-frequency.cpp)

## Problem
[Problem link](https://leetcode.com/problems/sort-characters-by-frequency/)

### Description
Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.

Return the *sorted string*. If there are multiple answers, return *any of them*.

### Examples
```
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```
```
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
```
```
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
```

### Constraints
- `1 <= s.length <= 5 * 105`
- `s` consists of uppercase and lowercase English letters and digits.


## Solution
This is obviously, just count the number of characters, sort by count and then print by frequency. I did this in Python because I know about the `Counter` class from `collections` library which does what we need. Then you can just use the `Counter().most_common()` function and create the result string.

I then also did it in 1 line, just for fun and to prove that I can.
The non one liner is the commented out bit in the file.

[sort-characters-by-frequency.py](./sort-characters-by-frequency.py)

Solved!
