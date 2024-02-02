# Word Break II
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/word-break-ii)

### Description
Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order**.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

### Input


- `1 <= s.length <= 20`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 10`
- `s` and `wordDict[i]` consist of only lowercase English letters.
- All the strings of `wordDict` are **unique**.
- Input is generated in a way that the length of the answer doesn't exceed 10^5.




### Examples
```
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
```

```
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
```

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
```


## Solution
Add each wordDict to an actual map. You can also have a map of prefixes so that you can terminate earlier. I didn't implement this in my solution because it would have probably just slowed it down, but if the input was larger then this would be very helpful.  

Then, go through each character and store them and see if they are in the word dict, if they are then recusively run the function on the remaining words.  

[word-break-ii.cpp](./word-break-ii.cpp)

Solved!

I'm not quite sure why Leetcode says I solved this in 0ms but I'll take it.  