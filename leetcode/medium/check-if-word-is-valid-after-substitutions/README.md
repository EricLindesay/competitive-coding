# Check If Word Is Valid After Substitutions
- [Problem](#problem)
- [Solution](#check-if-word-is-valid-after-substitutions.cpp)

## Problem
[Problem link](problem_link)

### Description
Given a string `s`, determine if it is **valid**.

A string `s` is **valid** if, starting with an empty string `t = ""`, you can **transform **`t`** into **`s` after performing the following operation **any number of times**:


	- Insert string `"abc"` into any position in `t`. More formally, `t` becomes `t<sub>left</sub> + "abc" + t<sub>right</sub>`, where `t == t<sub>left</sub> + t<sub>right</sub>`. Note that `t<sub>left</sub>` and `t<sub>right</sub>` may be **empty**.


Return `true` *if *`s`* is a **valid** string, otherwise, return* `false`.

### Input


- `1 <= s.length <= 2 * 10^4`
- `s` consists of letters `'a'`, `'b'`, and `'c'`




### Examples
```
Input: s = "aabcbc"
Output: true
Explanation:
"" -> "<u>abc</u>" -> "a<u>abc</u>bc"
Thus, "aabcbc" is valid.
```
```
Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "<u>abc</u>" -> "abc<u>abc</u>" -> "abcabc<u>abc</u>" -> "abcabcab<u>abc</u>c"
Thus, "abcabcababcc" is valid.
```
```
Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.
```


## Solution
My thoughts are to just repeatedly search for the string "abc" and remove it.  
Do this while the string is not empty and while the last operation resulted in a removal.  
Then, if the string is empty its valid. Otherwise it isn't.   

[check-if-word-is-valid-after-substitutions.cpp](./check-if-word-is-valid-after-substitutions.cpp)

Solved!