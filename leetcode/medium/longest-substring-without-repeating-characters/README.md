Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Medium

Given a string s, find the length of the longest substring without repeating characters.

 
Example 1:
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

Example 2:
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

Example 3:
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```
 
Constraints:
- 0 <= s.length <= 5 * 104
- s consists of English letters, digits, symbols and spaces


# Solution
Keep track of every character you've seen in a hashmap.
When you find a repeat, move the left pointer until you get to the first instance of the repeat in a while loop.

This can be made slightly more efficient in two ways
1. Just store it in a vector. There are 257 characters so store an array that size. This is less memory efficient but more time efficient.
2. Store the index of the first instance (or minus 1). Then you can directly set left to that pointer instead of needing the while loop.
    - On second thought you can't do this because you have to decrease all the characters in the way
    - On third thought, you CAN do this. If you keep track of whats the left most character, you can treat any character with a map[char] < left as a minus 1

[longest-substring-without-repeating-characters.cpp](./longest-substring-without-repeating-characters.cpp)

I implemented the second efficiency improvement here. I'm not going to implement the first efficiency improvement because I don't like how much memory is wasted. Realistically, 257 characters is not much memory at all but I like the scalability of my solution, so I am leaving it as is.  
[storing-index.cpp](./storing-index.cpp)


Solved!
