# Colored Rectangles - 1800

- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1398/D)  

You are given three multisets of pairs of colored sticks:   

`R` pairs of red sticks, the first pair has length `r_1`, the second pair has length `r_2`, `...`, the `R`-th pair has length `r_R`.  
`G` pairs of green sticks, the first pair has length `g_1`, the second pair has length `g_2`, `...`, the `G`-th pair has length `g_G`.  
`B` pairs of blue sticks, the first pair has length `b_1`, the second pair has length `b_2`, `...`, the `B`-th pair has length `b_B`.   
You are constructing rectangles from these pairs of sticks with the following process:   
- take a pair of sticks of one color
- take a pair of sticks of another color different from the first one
- add the area of the resulting rectangle to the total area. 
- Thus, you get such rectangles that their opposite sides are the same color and their adjacent sides are not the same color.  

Each pair of sticks can be used at most once, some pairs can be left unused. You are not allowed to split a pair into independent sticks.  

What is the maximum area you can achieve?  
  
### Input
The first line contains three integers `R`, `G`, `B` (`1 <= R, G, B <= 200`) — the number of pairs of red sticks, the number of pairs of green sticks and the number of pairs of blue sticks.  

The second line contains `R` integers `r_1, r_2, ..., r_R` (`1 <= r_i <= 2000`) — the lengths of sticks in each pair of red sticks.  

The third line contains `G` integers `g_1, g_2, ..., g_G` (`1 <= g_i <= 2000`) — the lengths of sticks in each pair of green sticks.  

The fourth line contains `B` integers `b_1, b_2, ..., b_B` (`1 <= b_i <= 2000`) — the lengths of sticks in each pair of blue sticks.  
  
### Output
Print the maximum possible total area of the constructed rectangles.

### Examples
```
Input
1 1 1
3
5
4
Output
20
```
```
Input
2 1 3
9 5
1
2 8 5
Output
99
```
```
Input
10 1 1
11 7 20 15 19 14 2 4 13 14
8
11
Output
372
```
### Note
In the first example you can construct one of these rectangles: red and green with sides `3` and `5`, red and blue with sides `3` and `4` and green and blue with sides `5` and `4`. The best area of them is `4 * 5 = 20`.  

In the second example the best rectangles are: red/blue `9 * 8`, red/blue `5 * 5`, green/blue `2 * 1`. So the total area is `72 + 25 + 2 = 99`.  

In the third example the best rectangles are: red/green `19 * 8` and red/blue `20 * 11`. The total area is `152 + 220 = 372`. Note that you can't construct more rectangles because you are not allowed to have both pairs taken to be the same color.


## Solution

### First Thoughts
First, sort them all in descending order.  
Then take the highest one and multiply it with the highest one from one of the other lists.  
However this doesn't work since if you have 
```
10 10
11
11
```
Then this would give 11*11 but you should do 10\*11 + 10\*11.  

So, choose each of the lists to be the lead and then pick from the other two based on highest. Then if you run out of the current list, you can easily find the highest multiplication of just those two lists.  

