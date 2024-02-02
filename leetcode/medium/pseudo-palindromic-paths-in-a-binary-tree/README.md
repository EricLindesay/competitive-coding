# Pseudo-Palindromic Paths in a Binary Tree
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree)

### Description
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be **pseudo-palindromic** if at least one permutation of the node values in the path is a palindrome.

*Return the number of **pseudo-palindromic** paths going from the root node to leaf nodes.*

### Input


- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 9`




### Examples
<img alt="" src="https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png" style="width: 300px; height: 201px;" />

```
Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
```

<img alt="" src="https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png" style="width: 300px; height: 314px;" />

```
Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
```

```
Input: root = [9]
Output: 1
```


## Solution

You can also do this using bitwise XOR instead of a charCount map.
Instead of adding to the map, do `path ^= (1 << node->val)` and instead of looping through the map, just count how many bits that value has set at 1.

[pseudo-palindromic-paths-in-a-binary-tree.cpp](./pseudo-palindromic-paths-in-a-binary-tree.cpp)

Solved!