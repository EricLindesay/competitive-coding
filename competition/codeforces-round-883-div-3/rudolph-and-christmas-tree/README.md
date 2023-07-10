# rudolph-and-christmas-tree
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://codeforces.com/contest/1846/problem/D)

### Description
Rudolph drew a beautiful Christmas tree and decided to print the picture. However, the ink in the cartridge often runs out at the most inconvenient moment. Therefore, Rudolph wants to calculate in advance how much green ink he will need.

The tree is a vertical trunk with identical triangular branches at different heights. The thickness of the trunk is negligible.

Each branch is an isosceles triangle with base `d` and height `h`, whose base is perpendicular to the trunk. The triangles are arranged upward at an angle, and the trunk passes exactly in the middle. The base of the `i`-th triangle is located at a height of `y_i`.

Example diagram on the problem link.

Help Rudolph calculate the total area of the tree branches.

### Input
The first line contains a single integer `t (1 ≤ t ≤ 10^4)` — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains three integers `n`, `d`, `h` `(1 ≤ n,d,h ≤ 2⋅10^5)` — the number of branches, the length of the base, and the height of the branches, respectively.

The second line of each test case contains `n` integers `y_i (1 ≤ y_i ≤ 10^9, y_1 < y_2 < ... < y_n)` — the heights of the bases of the branches.

The sum of `n` over all test cases does not exceed `2⋅10^5`.

### Output
For each test case, output a single real number on a separate line — the total area of the tree branches. The answer will be considered correct if its absolute or relative error does not exceed `10^−6`.

### Examples
```
Input
5
3 4 2
1 4 5
1 5 1
3
4 6 6
1 2 3 4
2 1 200000
1 200000
2 4 3
9 11
Output
11
2.5
34.5
199999.9999975
11.333333
```

## Solution

Finding the area of a triangle is easy.  
The hard bit is the overlap.  
I found the area of the triangle, then went to the next triangle, if it overlaps then remove the overlapping area.  
To get the overlapping area, its another triangle so you need base and height. Height is trivial to work out but base is more difficult. You have to use the property from GCSEs 6 years ago that the height and base length of a triangle are proportional. So you can find the base length easily if you know how much of the height is overlapping.  

[rudolph-and-christmas-tree.cpp](rudolph-and-christmas-tree.cpp)

Solevd! within competition

Make sure that it was not hacked before doing solved again.