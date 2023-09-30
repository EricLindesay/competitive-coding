# Verify This, Your Majesty
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/queens)

### Description

The “eight queens puzzle” is a classic puzzle where you have to place eight queens on a chess board in such a way that no queen can attack another queen. Remember that, in chess, queens can move in any direction (horizontal, vertical, and diagonal), which means the eight queens would have to be laid out in such a way that no two queens are on the same row, column, or diagonal.
This puzzle actually has multiple queens.cpps. The following is one possible queens.cpp: Finding the queens.cpps to the “eight queens puzzle” is actually an interesting computational problem. However, that’s not the problem you will be solving here. Instead, you will be solving a much simpler problem: given a proposed queens.cpp to the puzzle, you must verify whether it is a valid queens.cpp (i.e., whether no queen can attack another queen).
When referring to specific squares on the board, we will assume that the bottom-left square is the `(0,0)` square, and that the `x` coordinate increases as you move right, and the `y` coordinate increases as you move up.
In other words, something like this: Furthermore, we will consider the more general “`N`-queens puzzle”, where the chessboard can have `N* N` squares, and there will be `N` queens on the board. For example, this would be a correct queens.cpp to the 4-queens puzzle: And this would be an incorrect queens.cpp to the 4-queens puzzle: Notice how the queen in (2,2) can attack the queen in (0,2) and the queen in (2,3).

### Input
The input begins with a line containing a single integer: the value of `N` (`0 < N <= 5, 000`). This is followed by `N` lines, each containing the position of a queen as two integers: `x` and `y` (separated by a single space), where `0 <= x, y < N`.

### Output
The output contains either CORRECT if the positions of the queens is a queens.cpp to the `N`-queens puzzle, and INCORRECT otherwise.
Note that the sample data presented below corresponds to the three boards shows earlier. 

### Examples
```
Input

8
1 5
6 2
3 1
5 0
4 6
0 3
2 7
7 4
Output

CORRECT
```
```
Input

4
2 3
1 0
0 2
3 1
Output

CORRECT
```
```
Input

4
2 3
0 2
1 0
2 2
Output

INCORRECT
```
```
Input

8
1 5
6 2
3 1
5 0
4 6
0 3
2 7
7 4
Output

CORRECT
```
```
Input

4
2 3
1 0
0 2
3 1
Output

CORRECT
```
```
Input

4
2 3
0 2
1 0
2 2
Output

INCORRECT
```


## Solution
At first I was just going to check columns and rows using counting sort kind of thing but then Dom pointed out you need diagonals as well.  
My solution is O(n^2) which I think is the best you'll realistically get.  
I check rows and columns trivially and then to see if they are on the same diagonal, I just treat the two coordinates as points on a graph. 
If the gradient of the line which goes through both points is 1 (or -1) then they are attacking one another and the layout is invalid

[queens.cpp](./queens.cpp)

Solved!