# Find Kth Bit in Nth Binary String
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string)

### Description
Given two positive integers `n` and `k`, the binary string `S<sub>n</sub>` is formed as follows:


	- `S<sub>1</sub> = "0"`
	- `S<sub>i</sub> = S<sub>i - 1</sub> + "1" + reverse(invert(S<sub>i - 1</sub>))` for `i > 1`


Where `+` denotes the concatenation operation, `reverse(x)` returns the reversed string `x`, and `invert(x)` inverts all the bits in `x` (`0` changes to `1` and `1` changes to `0`).

For example, the first four strings in the above sequence are:


	- `S<sub>1 </sub>= "0"`
	- `S<sub>2 </sub>= "0**1**1"`
	- `S<sub>3 </sub>= "011**1**001"`
	- `S<sub>4</sub> = "0111001**1**0110001"`


Return *the* `k^th` *bit* *in* `S<sub>n</sub>`. It is guaranteed that `k` is valid for the given `n`.

### Input


- `1 <= n <= 20`
- `1 <= k <= 2^n - 1`




### Examples
```
Input: n = 3, k = 1
Output: "0"
Explanation: S<sub>3</sub> is "0111001".
The 1^st bit is "0".
```

```
Input: n = 4, k = 11
Output: "1"
Explanation: S<sub>4</sub> is "011100110110001".
The 11^th bit is "1".
```


## Solution

The input is small, n is less than 20. For the fastest solution, you could just preprocess it. Find the strings for n between 1 and 20 and then just look it up and return.  

However, the naive recursive solution itself just works, so do that.  

[find-kth-bit-in-nth-binary-string.cpp](./find-kth-bit-in-nth-binary-string.cpp)

Solved!