# Aquarium Tank
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/tank)

### Description
 Picture from Wikimedia Commons You just bought an “artistic” aquarium tank that has an interesting shape, and you poured `L` litres of water into the tank. How high is the water in the tank?
When you look at this tank from one side, it has the shape of a convex polygon. This polygon has exactly two vertices on the table (`y`-coordinates are 0), and all other vertices have positive `y`-coordinates. There are also exactly two vertices with maximum `y`-coordinates, and water is poured into the opening between these two vertices. This aquarium tank has a depth of `D` centimetres. The tank is glued to the table, so no matter what shape it has, it keeps its position and does not tip over.
All coordinates and lengths in this problem are given in centimetres. It should be noted that each cubic metre is equivalent to 1 000 litres.
An illustration showing the configuration of the tank of the first sample input is given below: 

### Input
The input consists of a single test case. The first line contains an integer `N` (`4 <= N <= 100`) giving the number of vertices in the polygon. The next line contains two integers `D` and `L`, where `1 <= D <= 1, 000` is the depth of the aquarium tank and `0 <= L <= 2, 000` is the number of litres of water to pour into the tank. The next `N` lines each contains two integers, giving the `(x,y)` coordinates of the vertices of the convex polygon in counterclockwise order. The absolute values of `x` and `y` are at most `1, 000`. You may assume that the tank has a positive capacity, and you never pour more water than the tank can hold.

### Output
Print the height of the water (in centimetres) in the aquarium tank on a line to 2 decimal places. 

### Examples
```
Input

4
30 50
20 0
100 0
100 40
20 40
Output

20.83
```
```
Input

9
30 70
110 70
100 80
80 80
-10 60
-40 30
-40 25
20 0
100 0
120 10
Output

19.74
```
```
Input

4
30 50
20 0
100 0
100 40
20 40
Output

20.83
```
```
Input

9
30 70
110 70
100 80
80 80
-10 60
-40 30
-40 25
20 0
100 0
120 10
Output

19.74
```


## Solution

### Shoelace Formula

Initial thought was to use the shoelace formula to work out the surface area of the side and from that calculate the volume of the tank.
The issue with that is that if you try and fill it, it may fill at different speeds depending on how narrow it is in that section, so you can't use that to work out the height of the water afterwards.

[tank.cpp](./tank.cpp)
