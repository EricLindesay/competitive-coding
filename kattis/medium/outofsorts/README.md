# Out of Sorts
- [Problem](#problem)
- [Solution](#outofsorts.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/outofsorts)

### Description

Ann Logan is fascinated with finite sequences of integers. She is particularly interested in sequences of the form `x_1, x_2, ... , x_ n` where: `x_{i} = (ax_{i-1}+c)\mod m`, `n`, `m`, `a`, and `c` are positive integer constants, `x_0` is a non-negative integer constant, and all `n` values are unique. For example, if `n=5`, `m=8`, `a=1`, `c=3`, and `x_0=3`, the sequence is `6`, `1`, `4`, `7`, `2` (`x_1 = (1\cdot 3+3)\mod 8 = 6`, `x_2 = (1\cdot 6+3)\mod 8 = 1`, and so on). Note that she does not consider the initial value `x_0` to be part of the sequence.
Ann wants to be able to quickly determine, for any integer value, whether or not it appears within a finite sequence of this form. Given values of `n`, `m`, `a`, `c`, and `x_0`, she plans to follow this list of steps: Generate the sequence `x_1,\cdots , x_ n` and store it in an array. Sort the array. Perform a binary search of the array for each integer of interest to her. Ann’s search algorithm, while not the most efficient possible, is pretty straightforward and understandable to anyone familiar with binary search: after calculating the midpoint mid at each step of the calculation (using mid = (low+high)/2), she first checks whether or not the value at location mid is equal to the search value x. If not, she then narrows the search according to whether x is strictly less than or strictly greater than the value at location mid.
Unfortunately, Ann is absent-minded and she lost her list of steps. She managed to remember the first and last step, but …she forgot to sort the array before performing her binary search! Needless to say, this means that many values that are in the (unsorted) array will not be found by a binary search, although surprisingly some can. In the example above, both `4` and `7` can be found with Ann’s binary search. How many values can be found for various sequences? Don’t botch it up!

### Input
Input consists of a line containing five integers `n`, `m`, `a`, `c`, and `x_0` (`1 <= n <= 10^6`, `1 <= m,a,c <= 2^{31}-1`, `0 <= x_0 <= 2^{31}-1`), where `n` is the length of the sequence `x_1, ... , x_ n` to be generated and `m`, `a`, `c`, and `x_0` are the constants used for generating the sequence. All values in the generated sequence are guaranteed to be unique.

### Output
Output the number of sequence values that could be found using Ann’s version of binary search, assuming she forgot to sort the sequence. 

### Examples
```
Input
5 8 1 3 3
Output
2
```
```
Input
6 10 1234567891 1 1234567890
Output
6
```


## Solution

[outofsorts.cpp](./outofsorts.cpp)