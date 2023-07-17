# 10kindsofpeople
[link](https://open.kattis.com/problems/10kindsofpeople)

Medium - 5.1

# Problem
## Description
The world is made up of kinds of people, those who understand binary and those who do not. These different kinds of people do not always get along so well. Bob might ask for a ounce coffee (meaning binary) and Alice might make misinterpret his request as being in decimal and give him a ounce coffee (binary). After Sue explains that this much coffee costs dollars (decimal), Bob might assume he only has to pay dollars (interpreting the price as being in binary). In response to these differences that are difficult to resolve, these two groups have divided the world into two regions, the binary-friendly zones and the decimal-friendly zones. They have even published a map like the following to help people keep up with where the areas are (they have used ones and zeros so nobody would have trouble reading it).

1111100000
1111000000
1110000011
0111100111
0011111111

Users of binary have to stay in the zones marked with a zero. Users of decimal have to stay in the zones marked with a one. You have to figure out if it is possible for either type of person to get between various locations of interest. People can move north, south, east or west, but cannot move diagonally.

## Input

Input starts with a line containing two positive integers, 1 <= `r` <= 1000 and 1 <= `c` <= 1000. The next `r` input lines give the contents of the map, each line containing exactly `c` characters (which are all chosen from 0 or 1).

The next line has an integer 0 <= `n` <= 1000. The following `n` lines each contain one query, given as four integers: `r1,c1` and `r2c2`. These two pairs indicate two locations on the map, and their limits are 1 <= `r1`, `r2` <= `r` and 1 <= `c1`, `c2` <= `c`.


## Output

For each query, output "binary" if a binary user can start from location `r1, c1` and move to location `r2, c2`. Output "decimal" if a decimal user can move between the two locations. Otherwise, output "neither".

### Examples
```
Input
1 4
1100
2
1 1 1 4
1 1 1 1
Output
neither
decimal
```

```
Input
10 20
11111111111111111111
11000000000000000101
11111111111111110000
11111111111111110000
11000000000000000111
00011111111111111111
00111111111111111111
10000000000000001111
11111111111111111111
11111111111111111111
3
2 3 8 16
8 1 7 3
1 1 10 20
Output
binary
decimal
neither
```

# Solution

## BFS
Use breadth-first search and see if there is a path between them.

This was too slow because it had to be repeated for every person.

[10kindsofpeople.cpp](./10kindsofpeople.cpp)

## Pre-process data and split into areas
Then I tried pre-processing all the data, putting them all into areas. If two cells are in the same area, they can be reached. I did this using flood fill.  
While doing this flood fill, replace the grid array with the area it is in, with the area being an integer >= 2.  

Then, if the destination and the source are in the same area, they must be reachable.  

[floodFill.cpp](./floodFill.cpp)

Solved!