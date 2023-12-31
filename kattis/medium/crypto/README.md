# Cryptographic Keys
- [Problem](#problem)
- [Solution](#crypto.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/crypto)

### Description

Lukáš invented a special cryptographic algorithm. He can not tell you the details, of course. However, there is one problem. He doesn’t know how to select strong keys for messages. Can you help him?
Suppose that a message is a positive integer `N`. The strongest key is an integer `K` such that `N` written in base `K` has the most zeros at the end. In case of a tie, the smallest such `K` is the strongest.
For example, the strongest key for `N = 72` is `K = 2`, because `72 = 1001000_2` (`72` written in base `2`) has `3` zeros at the end. Using base `3`, we only get `2` zeroes at the end (because `72 = 2200_3`), using base `6` would also give us `2` zeros, and no other base would give us more than `1` zero.

### Input
Input contains one line with one integer `N`, `2 <= N <= 10^{12}`.

### Output
Output contains one line with one integer `K` such that `N` written in base `K` has the most zeros at the end and is the smallest `K` with this property. 

### Examples
```
Input
72
Output
2
```


## Solution
Decompose the number into it's prime factors. While doing this, keep track of how many times the factor can decompose the number and keep track of the highest.  
Then print the factor associated with this highest decomposition.   

[crypto.cpp](./crypto.cpp)

Solved!