# rudolph-and-cut-the-rope 
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://codeforces.com/contest/1846/problem/A)

### Description
There are n nails driven into the wall, the i-th nail is driven ai meters above the ground, one end of the bi

meters long rope is tied to it. All nails hang at different heights one above the other. One candy is tied to all ropes at once. Candy is tied to end of a rope that is not tied to a nail.

To take the candy, you need to lower it to the ground. To do this, Rudolph can cut some ropes, one at a time. Help Rudolph find the minimum number of ropes that must be cut to get the candy.

### Input
The first line contains one integer `t (1≤t≤104)` — the number of test cases.

The first line of each test case contains one integer `n (1≤n≤50)` — the number of nails.

The `i`-th of the next `n` lines contains two integers `a_i` and `b_i` `(1≤a_i,b_i≤200)` — the height of the `i`-th nail and the length of the rope tied to it, all `a_i` are different.

It is guaranteed that the data is not contradictory, it is possible to build a configuration described in the statement.

### Output
For each test case print one integer — the minimum number of ropes that need to be cut to make the candy fall to the ground.

### Examples
```
Input
4
3
4 3
3 1
1 2
4
9 2
5 2
7 7
3 4
5
11 7
5 10
12 9
3 2
1 5
3
5 6
4 5
7 7
Output
2
2
3
0
```

## Solution

At first, I was confused by this problem, I didn't know how to do it.  
Looking at it a second time tho made it very easy.  

You have to cut every rope which is longer than its distance to the ground. I.e. `rope_height - rope_length > 0`. Count how many you cut and you get the output.  

[rudolph-and-cut-the-rope.cpp](./rudolph-and-cut-the-rope.cpp)

Solevd! within competition

Make sure that it was not hacked before doing solved again.