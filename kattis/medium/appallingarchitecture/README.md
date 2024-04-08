# Appalling Architecture
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/appallingarchitecture)

### Description
 Photo from Carlos ZGZ. You have recently been hired as an architect for the BAPC (Bureau of Architecture and Promising Constructions), responsible for top-quality buildings such as the Tower of Pisa. However, in the past couple of weeks, some of the structures that the BAPC have made have collapsed! It is up to you to figure out whether any other structures are in danger.
After some research it seems like the `x`-coordinate of the centers of gravity of some of the structures are off: if the center of gravity is too much to the left or to the right, the structure will fall over. Hence, you decide to check all the blueprints and see whether the structures are stable or not.
Given is a grid of up to size `100` by `100`, using characters in .#/\_`-. The `\texttt{.}` characters denote empty space, while each other character represents a completely filled `1* 1` box (any difference in symbols used is due to the artistic freedom of the other architects), whose center of mass is at the center of the box.
Every structure forms a single connected component that touches the ground, i.e. the bottom layer of the grid.
The structure falls to the left if the `x`-coordinate of the center of gravity is less than the `x`-coordinate of the leftmost point of the structure that touches the ground, and it falls to the right if the `x`-coordinate of the center of gravity is larger than the `x`-coordinate of the rightmost point of the structure that touches the ground. It is guaranteed that the center of gravity is never exactly above the leftmost or rightmost point where the building touches the ground.
Given a blueprint, is the structure balanced, does it fall to the left, or does it fall to the right?

### Input
 The first line has `1<= h <= 100` and `1<= w<= 100`, the height and width of the grid. Then follow `h` lines with `w` characters each. Each character is either ., indicating empty space, or one of #/\_`-, indicating a filled `1* 1` box . 

### Output
 Print a single line containing left, balanced, or right. 

### Examples
```
Input
3 3
/-\
|.|
#.#
Output
balanced
```
```
Input
3 3
...
___
..|
Output
left
```
```
Input
3 3
./\
.\/
.|.
Output
balanced
```
```
Input
20 19
...................
.........-____---..
........._/\\////-.
.......--//#\#\/_..
......._/\///////_.
......-/#######\/-.
......////\/#\#/_..
....../\#\#/////_..
....._/#####\#\/...
....._/\////////-..
...../########/-...
...._///\/#\#\/....
...._/#/#/\/\/_....
..._/\#######/-....
..._/\////////-....
.../\#\#\#\#/-.....
.._///\\\\#\/-.....
.._//////////-.....
..////##////-......
.-____##____.......
Output
balanced
```
```
Input
3 3
/-\
|.|
#.#
Output
balanced
```
```
Input
3 3
...
___
..|
Output
left
```
```
Input
3 3
./\
.\/
.|.
Output
balanced
```
```
Input
20 19
...................
.........-____---..
........._/\\////-.
.......--//#\#\/_..
......._/\///////_.
......-/#######\/-.
......////\/#\#/_..
....../\#\#/////_..
....._/#####\#\/...
....._/\////////-..
...../########/-...
...._///\/#\#\/....
...._/#/#/\/\/_....
..._/\#######/-....
..._/\////////-....
.../\#\#\#\#/-.....
.._///\\\\#\/-.....
.._//////////-.....
..////##////-......
.-____##____.......
Output
balanced
```


## Solution

[appallingarchitecture.cpp](./appallingarchitecture.cpp)