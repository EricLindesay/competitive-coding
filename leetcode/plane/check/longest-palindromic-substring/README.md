Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
Medium

Given a string s, return the longest palindromic substring in s.

 
Example 1:
```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

Example 2:
```
Input: s = "cbbd"
Output: "bb"
```
 

Constraints:
- 1 <= s.length <= 1000
- s consist of only digits and English letters.


```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        
    }
};
```

```py
class Solution:
    def longestPalindrome(self, s: str) -> str:
```

# Solution
Reverse the string, then check for palindromes in any position of any length, returning the first palindrome you find (loop from longest -> shortest palindromes).

I'm not sure if this solution will be fast enough since it is O(n^2 * substr efficiency)
[longest-palindrome-substring.cpp](longest-palindromic-substring.cpp)