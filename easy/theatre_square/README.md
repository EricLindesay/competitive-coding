# Theatre Square - 1000
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1/A)  

Theatre Square in the capital city of Berland has a rectangular shape with the size `n` × `m` meters. On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size `a` × `a`.  

What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.  
  
### Input
The input contains three positive integer numbers in the first line: `n`,  `m` and `a` (`1 ≤  n, m, a ≤ 10^9`).  
  
### Output
Write the needed number of flagstones.  

### Examples
```
Input
6 6 4
Output
4
```


## Solution

Don't you just have to find the area of n*m and then divide it by a^2?  
No you can't do that because LSF and ASF thingy.  
Instead you must do `n/a * m/a`, finding the ceiling of each division.  
[theatre_square.cpp](theatre_square.cpp)  

Solved!
