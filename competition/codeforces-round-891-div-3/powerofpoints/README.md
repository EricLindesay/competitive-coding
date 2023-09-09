# Power of Points
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](problem_link)

### Description
You are given n points with integer coordinates x1,…xn, which lie on a number line.

For some integer s, we construct segments [s,x1], [s,x2], …, [s,xn]. Note that if xi<s, then the segment will look like [xi,s]. The segment [a,b] covers all integer points a,a+1,a+2,…,b.

We define the power of a point p
as the number of segments that intersect the point with coordinate p, denoted as fp.

Your task is to compute ∑p=1109fp
for each s∈{x1,…,xn}, i.e., the sum of fp for all integer points from 1 to 109.

For example, if the initial coordinates are [1,2,5,7,1]
and we choose s=5, then the segments will be: [1,5],[2,5],[5,5],[5,7],[1,5]. And the powers of the points will be: f1=2,f2=3,f3=3,f4=3,f5=5,f6=1,f7=1,f8=0,…,f109=0. Their sum is 2+3+3+3+5+1+1=18.

### Input
The first line contains an integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains an integer n
(1≤n≤2⋅105) — the number of points.

The second line contains n
integers x1,x2…xn (1≤xi≤109) — the coordinates of the points.

It is guaranteed that the sum of the values of n
over all test cases does not exceed 2⋅105.

### Output
For each test case, output n integers, where the i-th integer is equal to the sum of the powers of all points for s=xi.

### Examples
```
Input
3
3
1 4 3
5
1 2 5 7 1
4
1 10 100 1000

Output
8 7 6
16 15 18 24 16
1111 1093 1093 2893
```

## Solution
### Initial thoughts
This one gives a lot of detail which you actually don't need, you can simplify a lot of it. You don't actually have to consider how many overlap, it's just the sum of differences from the left and right (plus one each).

My initial solution was to go through each value in the list to find the `s` value you will be using and then go through the array again (inner for loop, `O(n^2)` total) and find the difference from `s` to each element, add that to the sum and then add one every time as well (since you want it to be left and right inclusive).

I then did hashing so that if you get two of the same `s` values, you don't rerun the entire calculations. The sum will be the same no matter where in the list the number is.  
This prevents test cases like `1 1 1 1 1 1 1 1 1 ... 1`

This, as expected, this is too slow.  

[powerofpoints.cpp](./powerofpoints.cpp)

### Further thoughts
Something which I have a vague idea of how to make it better is something to do with the sum. If you find the sum of all the elements and then do `sum -= n * min_value`, you can normalise the values to start from `0`. The problem then is how to code the logic to "remove" each `s` value from the sum, one at a time, and see how it affects the sum.  