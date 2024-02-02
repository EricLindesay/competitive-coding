# Longest String Chain
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/longest-string-chain)

### Description
You are given an array of `words` where each word consists of lowercase English letters.

`word<sub>A</sub>` is a **predecessor** of `word<sub>B</sub>` if and only if we can insert **exactly one** letter anywhere in `word<sub>A</sub>` **without changing the order of the other characters** to make it equal to `word<sub>B</sub>`.


	- For example, `"abc"` is a **predecessor** of `"ab**a**c"`, while `"cba"` is not a **predecessor** of `"bcad"`.


A **word chain*** *is a sequence of words `[word<sub>1</sub>, word<sub>2</sub>, ..., word<sub>k</sub>]` with `k >= 1`, where `word<sub>1</sub>` is a **predecessor** of `word<sub>2</sub>`, `word<sub>2</sub>` is a **predecessor** of `word<sub>3</sub>`, and so on. A single word is trivially a **word chain** with `k == 1`.

Return *the **length** of the **longest possible word chain** with words chosen from the given list of *`words`.

### Input


- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 16`
- `words[i]` only consists of lowercase English letters.




### Examples
```
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
```

```
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
```

```
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
```


## Solution

### O(n^2 * k) Solution
Essentially, create a tree structure.  

For each word, you have the root word and then that word's predecessors connected. Then just find the highest tree.  
Have some way to have fast lookup for "is word A a direct predecessor of word B" if already seen.

Go through each word, go through all the words and find which are direct predecessors and store that somewhere. Then, recursively (with hashing) traverse the tree to find the highest depth.  

You can have a minor optimisation for this by sorting the list of words by size before doing anything. Then you can reduce repetition, and reduce the chances of trying to find whether words of the same length are predecessors.   

The `k` in the big O notation is the length of the string (due to finding the predecessor).

[longest-string-chain.cpp](./longest-string-chain.cpp)

Solved!

### There exists an O(n*k) solution using DP apparenlty

Instead of "building up words", you break them down. So go through from the longest words first and then remove each character in turn from the word and store it in the hashmap with + 1 to the current value for the word before you started removal.

Then, at the end, loop through each actually inputted word and find the max of the values stored in the map.