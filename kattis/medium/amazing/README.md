# A Mazing!
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/amazing)

### Description
A maze consists of a collection of equal sized square cells, where any or all of the sides may be a wall or a door. The maze may have no exit or multiple exits. Cells are typically arranged so that they may share sides with other cells as shown in the four sample mazes below:
\includegraphics[width=.6\textwidth ]{amazing-001.png}
Figure 1: (The numbers in the cells above are for illustrative purposes only.)

Each side of a cell is labeled with a direction to allow navigation:
\includegraphics[width=.2\textwidth ]{amazing-002.png}

For each maze, the starting point is someplace in the maze (for example, any of the numbered cells in the samples above). In the samples above:

    Maze A has no way out.

    Maze B has an exit (solution) to the right of cell 2.

    Maze C has an exit down from cell 3, unless the starting point is cell 5, in which case there is no way out

    Maze D has an exit up from cell 6.

For example, using Maze D above, if the starting point is cell 9, one possible set of directions to get to the exit would be: right, right, right, right, right, up, up, up.

For this problem, you will write a program that finds an exit to a maze. Your program must operate interactively. That is, your program will make a move by providing a direction (right, down, left or up), and the judging software will send back one of four responses:

    wall - indicates that a wall is there and you cannot proceed in that direction

    ok - indicates that there is door there and you may proceed in that direction to the neighboring cell.

    solved - indicates that you have successfully found an exit to the maze.

    wrong - indicates that your program made an error, as discussed below.

If your program determines there is no way out of the maze, you should send the precise string “no way out” (without the quotes) instead of a direction. If there is in fact no way out of the maze, you will receive a solved reply.

Your program will receive a wrong indication if any of the following occur:

    Your program sends “no way out”, even though there is a way out.

    Your program makes the same move (direction) from the same cell twice.

After receiving a wrong or a solved reply, your program should exit.

### Input/Output
This is an interactive program. The input you receive is a function of the output you generate. All input and output strings must end in a new-line character. You should never send extra blank lines.

You must make sure that your program’s standard output stream is flushed after you output a the new-line character that completes a command. This is accomplished with System.out.flush() in Java, stdout.flush() in Python, fflush(stdout) in C, and cout << flush in C++.

The first thing your program must do when it starts up is to send its first move (up, down, right or left), followed by a new-line character. It will then wait for a new-line terminated response on the standard input. The response will be one of wall, ok, solved, or wrong indication. Your program will then make another move based on the response it received as discussed above. This process will repeat until your program receives a wrong or solved indication.

Example (User output in Teletype, Computer judge output in Bold). (This sample run has no relationship to the samples shown above).

Sample Run

down

wall

right

wall

left

wall

up

ok

right

ok

down

ok

down

wall

right

wall

left

wall

up

ok

right

solved

It is guaranteed that the maze will not be larger than 
in any dimension.


## Solution
My thoughts is "look up some maze solving algorithms and just follow that". So I found [Trémaux's algorithm](https://en.wikipedia.org/wiki/Maze-solving_algorithm) but then I noticed a problem, the second condition of a "wrong" indication. To follow this algorithm, you need to know how many walls/open positions that cell has, however, you can't test all of them and then choose one of them without repeating an exit, which will cause the "wrong" to occur.

Do recursive descent parsing kind of thing.
Keep a queue of directions that you go in (successfully).
Keep track of what directions you leave cells. 
If you ever get to a cell you have seen before, exit it through an unvisted direction. If it doesn't have an unvisited direction (except from where you came), pop from the directions queue and go in the opposite direction, then check if you can go either direction again.
Then, if the queue is ever empty and there is no where to go for the current cell, there is no solution to the maze. Otherwise, you would have found the solution at one point or another.

[amazing.cpp](./amazing.cpp)