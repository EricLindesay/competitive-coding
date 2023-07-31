# rudolf-and-snowflakes-simple-version
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://codeforces.com/contest/1846/problem/E1)

### Description
This is a simple version of the problem. The only difference is that in this version `n ≤ 10^6`.

One winter morning, Rudolf was looking thoughtfully out the window, watching the falling snowflakes. He quickly noticed a certain symmetry in the configuration of the snowflakes. And like a true mathematician, Rudolf came up with a mathematical model of a snowflake.

He defined a snowflake as an undirected graph constructed according to the following rules:
- Initially, the graph has only one vertex.
- Then, more vertices are added to the graph. The initial vertex is connected by edges to `k` new vertices `(k > 1)`.
- Each vertex that is connected to only one other vertex is connected by edges to `k` more new vertices. This step should be done at least once. 

The smallest possible snowflake for `k = 4` is shown in the figure on the link.

After some mathematical research, Rudolf realized that such snowflakes may not have any number of vertices. Help Rudolf check if a snowflake with `n` vertices can exist.
    
### Input
The first line of the input contains an integer `t` `(1 ≤ t ≤ 10^4)` — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains an integer `n` `(1 ≤ n ≤ 10^6)` — the number of vertices for which it is necessary to check the existence of a snowflake.

### Output
Output `t` lines, each of which is the answer to the corresponding test case — "YES" if there exists such `k > 1` for which a snowflake with the given number of vertices can be constructed; "NO" otherwise.

### Examples
```
Input
9
1
2
3
6
13
15
255
10101
1000000
Output
NO
NO
NO
NO
YES
YES
YES
YES
NO
```

## Solution

The number of vertexes follow the geometric formula: `1 + k + k^2 + ...`. This has a sum which is equal to `sum = 1 * (1 - k^ceil(log_k(b)))/(1 - k)`.

I then looped through every value of `k` to see if the sum (according to that formula) is equal to n, if it is then great otherwise continue looking.  

[rudolf-and-snowflakes-simple-version.cpp](rudolf-and-snowflakes-simple-version.cpp)

Solevd! within competition

Make sure that it was not hacked before doing solved again.