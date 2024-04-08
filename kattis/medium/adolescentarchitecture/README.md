# Adolescent Architecture
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/adolescentarchitecture)

### Description
 Building blocks by Thaliesin on Pixabay Little Peter is building a stack out of his toy blocks. He is using two kinds of blocks – cubes and cylinders – and wants to stack all of them into a single tower, where each block other than the topmost block has a single block standing on it. In order for the tower to be stable, the outline of each block needs to be fully contained within the outline of the block below when looking at the tower from above (the outlines are allowed to touch). Is it possible to construct such a tower, and if so, in which order do the blocks need to be stacked?

### Input
The input consists of: One line with an integer `n` (`1 <= n <= 100`), the number of blocks. `n` lines, each with the description of a block. The description consists of a string giving the type of block (cube or cylinder) and an integer `a` (`1 <= a <= 1, 000`) giving the size of the block – if the block is a cube then `a` is its side length, and if it is a cylinder then `a` is the radius of its base (note that the height of the cylinder does not matter). 

### Output
If there is no way to construct the tower, output impossible. Otherwise output `n` lines, giving the order in which to stack the blocks from top to bottom. 

### Examples
```
Input
3
cube 7
cube 11
cylinder 5
Output
cube 7
cylinder 5
cube 11
```
```
Input
2
cube 5
cylinder 3
Output
impossible
```
```
Input
3
cube 4
cylinder 2
cube 4
Output
cylinder 2
cube 4
cube 4
```
```
Input
3
cube 7
cube 11
cylinder 5
Output
cube 7
cylinder 5
cube 11
```
```
Input
2
cube 5
cylinder 3
Output
impossible
```
```
Input
3
cube 4
cylinder 2
cube 4
Output
cylinder 2
cube 4
cube 4
```


## Solution

[adolescentarchitecture.cpp](./adolescentarchitecture.cpp)

Solved!