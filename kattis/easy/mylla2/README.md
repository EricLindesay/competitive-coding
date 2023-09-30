# Mylla
- [Problem](#problem)
- [Solution](#mylla2.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/mylla2)

### Description
 Image from wikimedia.org Hjalti’s favourite game is tic tac toe. The game is played by two players who take turns placing marks inside the cells of a `3 * 3` grid, but they can’t place marks in cells that already have marks. The starting player uses the mark X and the other uses the mark O. A player wins if they place three instances of their mark in a straight line, whether that be horizontally, vertically or diagonally. The game ends when a player wins or ends in a tie if there are no empty cells left.
Hjalti is a very competitive person and loves nothing more than beating Guðjón at tic tac toe. Hjalti claims he’s far better at the game than Guðjón so he allows Guðjón to make the first move in every game. Since there is a bit of rivalry between them they don’t trust each other to verify the results of the games. Thus they ask you, a third party, to verify the results. Hjalti doesn’t care whether Guðjón won or not, just whether he himself won or not.

### Input
The input consists of three lines, each line being a row of the game board. Each row can contain the letters X, O or _, where X are cells marked by Guðjón, O are cells marked by Hjalti and _ are the empty cells. The input is always a valid end state of the game.

### Output
Print Jebb if Hjalti won, otherwise print Neibb.
Scoring Group Points Constraints 1 100 No further constraints 

### Examples
```
Input
OOO
XX_
_X_
Output
Jebb
```
```
Input
XOX
XOO
X__
Output
Neibb
```
```
Input
OXO
XXO
XOX
Output
Neibb
```
```
Input
OOO
XX_
_X_
Output
Jebb
```
```
Input
XOX
XOO
X__
Output
Neibb
```
```
Input
OXO
XXO
XOX
Output
Neibb
```


## Solution

[mylla2.cpp](./mylla2.cpp)

Solved!