# Deadly Laser - 1000
**Tags**: Implementation  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1721/B)  

The robot is placed in the top left corner of a grid, consisting of `n` rows and `m` columns, in a cell `(1, 1)`.  

In one step, it can move into a cell, adjacent by a side to the current one:   

 - `(x, y) \rightarrow (x, y + 1)`; 
- `(x, y) \rightarrow (x + 1, y)`; 
- `(x, y) \rightarrow (x, y - 1)`; 
- `(x, y) \rightarrow (x - 1, y)`. 
The robot can't move outside the grid.  

The cell `(s_x, s_y)` contains a deadly laser. If the robot comes into some cell that has distance less than or equal to `d` to the laser, it gets evaporated. The distance between two cells `(x_1, y_1)` and `(x_2, y_2)` is `|x_1 - x_2| + |y_1 - y_2|`.  

Print the smallest number of steps that the robot can take to reach the cell `(n, m)` without getting evaporated or moving outside the grid. If it's not possible to reach the cell `(n, m)`, print `-1`.  

The laser is neither in the starting cell, nor in the ending cell. The starting cell always has distance greater than `d` to the laser.  
  
### Input
The first line contains a single integer `t` (`1 <= t <= 10^4`) — the number of testcases.  

The only line of each testcase contains five integers `n, m, s_x, s_y, d` (`2 <= n, m <= 1000`; `1 <= s_x <= n`; `1 <= s_y <= m`; `0 <= d <= n + m`) — the size of the grid, the cell that contains the laser and the evaporating distance of the laser.  

The laser is neither in the starting cell, nor in the ending cell (`(s_x, s_y) \neq (1, 1)` and `(s_x, s_y) \neq (n, m)`). The starting cell `(1, 1)` always has distance greater than `d` to the laser (`|s_x - 1| + |s_y - 1| &gt; d`).  
  
### Output
For each testcase, print a single integer. If it's possible to reach the cell `(n, m)` from `(1, 1)` without getting evaporated or moving outside the grid, then print the smallest amount of steps it can take the robot to reach it. Otherwise, print `-1`.

### Examples
```
Input
3
2 3 1 3 0
2 3 1 3 1
5 5 3 4 1
Output
3
-1
8
```


-----
## Solution

### Initial Thoughts
Use dijkstra's to find the shortest path to the thing if it exists.  
This keeps on giving me a runtime error but I'm not sure why.  
[dijkstra.cpp](/dijkstra.cpp)  


