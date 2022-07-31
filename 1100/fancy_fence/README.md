# Fancy Fence - 1100
**Tags**: Geometry, Implementation, Maths  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/270/A)  

Emuskald needs a fence around his farm, but he is too lazy to build it himself. So he purchased a fence-building robot.  

He wants the fence to be a regular polygon. The robot builds the fence along a single path, but it can only make fence corners at a single angle `*a*`.  

Will the robot be able to build the fence Emuskald wants? In other words, is there a regular polygon which angles are equal to `*a*`?  
  
### Input
The first line of input contains an integer `*t*` (`0 &lt; *t* &lt; 180`) — the number of tests. Each of the following `*t*` lines contains a single integer `*a*` (`0 &lt; *a* &lt; 180`) — the angle the robot can make corners at measured in degrees.  
  
### Output
For each test, output on a single line "`YES`" (without quotes), if the robot can build a fence Emuskald wants, and "`NO`" (without quotes), if it is impossible.

### Examples
```
Input
3
30
60
90
Output
NO
YES
YES
```

### Note
In the first test case, it is impossible to build the fence, since there is no regular polygon with angle `.  

In the second test case, the fence is a regular triangle, and in the last test case — a square.


-----
## Solution

### Initial Thoughts
The sum of interior angles of a regular polygon is `180*(n-2)` and each individual angle is that divided by `n`.  
You can then set that individual angle to the input. If you can rearrange the equation and find an `n` which is an integer then print `YES`. Otherwise, `NO`.
```
180*(n-2)/n = a
180n - 360 = an
180n - an = 360
n(180 - a) = 360
n = 360/(180 - a)
```
[fancy_fence.cpp](./fancy_fence.cpp)  


Solved!  
