Regular Expression Matching
https://leetcode.com/problems/regular-expression-matching/
Hard

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
- '.' Matches any single character.​​​​
- '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

 
Example 1:
```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

Example 2:
```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

Example 3:
```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```
 
Constraints:
- 1 <= s.length <= 20
- 1 <= p.length <= 20
- s contains only lowercase English letters.
- p contains only lowercase English letters, '.', and '*'.
- It is guaranteed for each appearance of the character '*', there will be a previous valid character to match


```cpp
class Solution {
public: 
    bool isMatch(string s, string p) {
        
    }
};
```

```py
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
```

## Solution
### Eating 
Eating - take as many characters from `s` as possible which match the starred character.
Vomiting - take as many characters from `re` and make sure that you have enough characters in `numEaten` to match the regex.

If the current character is starred, then eat as many as possible.
If the current character isn't starred BUT it matches the starred character, reduce numEaten by 1. If numEaten is ever negative, return false.
If the current character isn't starred and doesnt match the starred, delete the starred character and make sure the string matches the current character.

This works currently in [wildcard.cpp](wildcard.cpp) except, I have to implement it so that when you vomit, the character you vomit is valid in the string.

Store the words you eat (you don't actually have to store because you have the string), in the order you eat them.
Then when you finish vomiting everything, (lets say you vomit 2 characters out of 4 eaten). Check that the last two of the 4 eaten are equal to the 2 vomited (but opposite order).

So
`s = ab, r = .*c`
See `.*`, eat a and b.
You see c, c matches ., vomit c.
Check that c == b. Oh it doesn't? return false

`s = ab, r = .*bc`
See `.*`, eat a and b.
Vomit b and c. Two numbers were vomited.
Check that a == b and b == c. Oh it doens't? return false

`s = ab, r = .*b`
See `.*`, eat a and b.
Vomit b from regex. One number was vomited.
Check that b == b, it does, great.

Further work on the problem shows that this doesn't work.
For things like `a*b*a*`, it provides problems for something like `aaba`.
This would have been a O(n) solution but didn't work unfortunately.
[better-vomiting.cpp](better-vomiting.cpp) was the closest I got to a working solution using this method.

### Recursion
Instead I tried recursion.  
Recusion when looping over a star, ignoring the star or accepting the star exactly once.  
This seemed to work and I added in some memory to remember previous solutions to reduce repetition for the recursion.  
The key for the memory was `(index of s) * 30 + (index of regex)`. We got told in the problem that `s` is at most 20 characters long, so we can gaurantee that the key is unique using that forumla. You could have also used `* 20` but to be safe, I chose 30.  
[recursion.cpp](recursion.cpp)

Solved!
