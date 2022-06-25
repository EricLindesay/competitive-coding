# Woodcutters - 1500
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/545/C)  

Little Susie listens to fairy tales before bed every day. Today's fairy tale was about wood cutters and the little girl immediately started imagining the choppers cutting wood. She imagined the situation that is described below.  

There are `n` trees located along the road at points with coordinates `x_1`, `x_2`, ..., `x_n`. Each tree has its height `h_i`. Woodcutters can cut down a tree and fell it to the left or to the right. After that it occupies one of the segments `[x_i - h_i, x_i]` or `[x_i; x_i + h_i]`. The tree that is not cut down occupies a single point with coordinate `x_i`. Woodcutters can fell a tree if the segment to be occupied by the fallen tree doesn't contain any occupied point. The woodcutters want to process as many trees as possible, so Susie wonders, what is the maximum number of trees to fell.   
  
### Input
The first line contains integer `n` (`1 ≤ n ≤ 10^5`) — the number of trees.  

Next `n` lines contain pairs of integers `x_i`, `h_i` (`1 ≤ x_i, h_i ≤ 10^9`) — the coordinate and the height of the `і`-th tree.  

The pairs are given in the order of ascending `x_i`. No two trees are located at the point with the same coordinate.  
  
### Output
Print a single number — the maximum number of trees that you can cut down by the given rules.  

### Examples
```
Input
5
1 2
2 1
5 10
10 9
19 1
Output
3
```
```
Input
5
1 2
2 1
5 10
10 9
20 1
Output
4
```

### Note
In the first sample you can fell the trees like that:   
- fell the `1`-st tree to the left — now it occupies segment `[-1;1]` 
- fell the `2`-nd tree to the right — now it occupies segment `[2;3]` 
- leave the `3`-rd tree — it occupies point `5` `` leave the `4`-th tree — it occupies point `10` 
- fell the `5`-th tree to the right — now it occupies segment `[19;20]`   

In the second sample you can also fell `4`-th tree to the right, after that it will occupy segment `[10;19]`.


## Solution

Two things I first took note of, you can always fell the left most tree to the left and the right most tree to the right.  

### Occupied Array
For this, I took an array which has the same length as the highest distance and assigned them all values 0 or tree_height (if occupied).  
This then allowed me to loop through this new array, find whether the tree could fit in the distance and if it could, increment the trees_felled counter.  
This method takes O(d) time where d is the position of the last tree.  
[occupied_array.cpp](solutions/occupied_array.cpp)

### Direct Calculation
In the previous method, I noted that if a spot was occupied by a cut down tree, I would assign it the value -1. However, I noticed that I never actually had to assign the value of -1 to any position in the array.  
This meant that the occupied_array was totally unnecessary, you can just use the relative positions to calculate whether the tree can fall.  
This method now takes O(n) time where n is how many trees you have.  
This is much better than the previous one.  
[direct_subtraction.cpp](solutions/direct_subtraction.cpp)  

Solved!
