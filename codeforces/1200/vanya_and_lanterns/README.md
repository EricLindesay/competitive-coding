# Vanya and Lanterns - 1200
**Tags**: Binary Search, Implementation, Maths, Sorting  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/492/B)  

Vanya walks late at night along a straight street of length `*l*`, lit by `*n*` lanterns. Consider the coordinate system with the beginning of the street corresponding to the point `0`, and its end corresponding to the point `*l*`. Then the `*i*`-th lantern is at the point `*a*`*i*``. The lantern lights all points of the street that are at the distance of at most `*d*` from it, where `*d*` is some positive number, common for all lanterns.   

Vanya wonders: what is the minimum light radius `*d*` should the lanterns have to light the whole street?  
  
### Input
The first line contains two integers `*n*`, `*l*` (`1 ≤ *n* ≤ 1000`, `1 ≤ *l* ≤ 10`9``) — the number of lanterns and the length of the street respectively.   

The next line contains `*n*` integers `*a*`*i*`` (`0 ≤ *a*`*i*` ≤ *l*`). Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.  
  
### Output
Print the minimum light radius `*d*`, needed to light the whole street. The answer will be considered correct if its absolute or relative error doesn't exceed `10` - 9``.

### Examples
```
Input
7 1515 5 3 7 9 14 0
Output
2.5000000000
```
```
Input
2 52 5
Output
2.0000000000
```

### Note
Consider the second sample. At `*d* = 2` the first lantern will light the segment `[0, 4]` of the street, and the second lantern will light segment `[3, 5]`. Thus, the whole street will be lit.


-----
## Solution

### Initial Thoughts
If you go between each lantern. You need to find the minimum between any two consecutive lanterns.  
The answer would then be this but halved. Also include 0 and the length of the road as points since you need to get from the start and to the end correctly.  
So we need to store all of the lanterns and sort them.  
This was correct. I feel like it could be improved but I don't know how and it is fast enough.  
My initial code was correct, however, using `cout` converts large numbers into scientific notation and the answers must have been in the form of a whole number.  
Changing that to `printf` made it work correctly.  
[vanya_and_lanterns.cpp](vanya_and_lanterns.cpp)  


Solved!  
