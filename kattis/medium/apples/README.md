# Falling Apples
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/apples)

### Description
 You have a 2D rectangular grid. Each grid cell contains either an apple, an obstacle, or is empty. Empty cells are denoted as ’.’, apples as ’a’, and obstacles as ’#’. You are to implement a simulation of gravity, based on the following rules: The obstacles do not move. Whenever there is an empty cell immediately below an apple, the apple moves into the empty cell. Print out the final configuration of the board after all apples reach their final locations. Merely iterating the gravity rule, a step at a time, will likely take too long on large datasets.


### Input
The input begins with a line containing integers `R` and `C`, designating the number of rows and columns of the grid, such that `1 <= R <= 50, 000` and `1 <= C <= 10`. The first line is followed by `R` additional lines, each designating a row of the grid, from top to bottom. Each line has `C` characters, each of which is either ’.’, ’a’, or ’#’.

### Output
Output `R` grid lines displaying the final state. 

### Examples
```
Input

3 3
aaa
#..
..#
Output

a..
#.a
.a#
```
```
Input

4 5
aaa.a
aa.a.
a.a..
...a.
Output

.....
a....
aaaa.
aaaaa
```
```
Input

3 3
aaa
#..
..#
Output

a..
#.a
.a#
```
```
Input

4 5
aaa.a
aa.a.
a.a..
...a.
Output

.....
a....
aaaa.
aaaaa
```


## Solution

This one is pretty simple, just count how many apples are in the column and then when you reach an obstacle, go backwards and set all of them to apples as appropriate.

[apples.cpp](./apples.cpp)

Solved!

Solved during the University of Nottingham coding competition.