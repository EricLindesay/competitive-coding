# Love Triangle - 800
**Tags**: Graphs  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/939/A)  

As you could know there are no male planes nor female planes. However, each plane on Earth likes some other plane. There are `*n*` planes on Earth, numbered from `1` to `*n*`, and the plane with number `*i*` likes the plane with number `*f*`*i*``, where `1 ≤ *f*`*i*` ≤ *n*` and `*f*`*i*` ≠ *i*`.  

We call a love triangle a situation in which plane `*A*` likes plane `*B*`, plane `*B*` likes plane `*C*` and plane `*C*` likes plane `*A*`. Find out if there is any love triangle on Earth.  
  
### Input
The first line contains a single integer `*n*` (`2 ≤ *n* ≤ 5000`) — the number of planes.  

The second line contains `*n*` integers `*f*`1`, *f*`2`, ..., *f*`*n*`` (`1 ≤ *f*`*i*` ≤ *n*`, `*f*`*i*` ≠ *i*`), meaning that the `*i*`-th plane likes the `*f*`*i*``-th.  
  
### Output
Output «`YES`» if there is a love triangle consisting of planes on Earth. Otherwise, output «`NO`».  

You can output any letter in lower case or in upper case.

### Examples
```
Input
52 4 5 1 3
Output
YES
```
```
Input
55 5 5 5 1
Output
NO
```

### Note
In first example plane `2` likes plane `4`, plane `4` likes plane `1`, plane `1` likes plane `2` and that is a love triangle.  

In second example there are no love triangles.


-----
## Solution

### Initial Thoughts
A brute force solution is O(4n) time.  
Go through each value in the list.  
Go to the index that points to, then to the index that that points to.  
If that value is equal to the original index, then there is a love traingle. Otherwise, there isn't.  
The fourth n is because you have to read in the entire list once as well.  
This worked.  
[love_triangle.cpp](./love_triangle.cpp)  

Solved!  