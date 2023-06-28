Palindrome Number
https://leetcode.com/problems/palindrome-number/
Easy

Given an integer x, return true if x is a palindrome, and false otherwise.


Example 1:
```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

Example 2:
```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

Example 3:
```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```
 
Constraints:

- -2^31 <= x <= 2^31 - 1

 
Follow up: Could you solve it without converting the integer to a string?


```py
class Solution:
    def isPalindrome(self, x: int) -> bool:
```

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        
    }
};
```

# Solution
Well you could convert it to a string and check whether its a palindrome.
I want to try it without the conversion tho, I want to do the follow up task.
My thoughts is something like this
- If its negative, return false
- Get the number of digits by repeatedly dividing by 10
- Loop through from 0 -> num_digits/2
- See if mod pow(10, i) and mod pow(10, num_digits-i) are the same
    - You actually need to do a little more maths for this.
    - The lower digit is `x % pow(10, i+1) / pow(10, i)`
    - The upper digit is `x / pow(10, digits-i-1) % 10`


Solved!