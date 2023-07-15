# logo2
- [Problem](#problem)
- [Solution](#logo2.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/logo2)

### Description
Logo is a programming language built around a turtle. Commands in the language cause the turtle to move. The turtle has a pen attached to it. As the turtle moves, it draw lines on the page. The turtle can be programmed to draw interesting pictures.

We are interested in making the turtle draw a picture, then return to the point that it started from. For example, we could give the turtle the following program:

fd 100 lt 120 fd 100 lt 120 fd 100

The command fd causes the turtle to move forward by the specified number of units. The command lt causes the turtle to turn left by the specified number of degrees. Thus the above commands cause the turtle to draw an equilateral triangle with sides 100 units long. Notice that after executing the commands, the turtle ends up in the same place as it started. The turtle understands two additional commands. The command bk causes the turtle to move backward by the specified number of units. The command rt causes the turtle to turn right by the specified number of degrees. The distances and angles in all commands are always non-negative integers.

Unfortunately, we have been messy in writing the program down, and cannot read our own writing. One of the numbers in the program is missing. Assuming the turtle ends up at the place that it started at the end of its journey, can you find the missing number?

### Input
The first line of input contains one integer specifying the number of test cases to follow, at most 20. Each test case starts with a line containing one integer, the number of commands to follow. The commands follow, one on each line. Each test case will contain no more than 1000 commands. The argument of each command is either an integer or a question mark (?). There will be exactly one question mark in each test case.

### Output
For each test case, output line containing a single integer such that when the question mark in the program is replaced by , the turtle ends up at the same point that it started from once the program completes. If the question mark is the argument of an lt or rt command, the angle in the output must be between 0 and 359 degrees, inclusive. The correct answer will always be an integer, and we guarantee that for every test case, there will be only one correct answer.

### Examples
```
Input
1
5
fd 100
lt 120
fd ?
lt 120
fd 100
Output
100
```
```
Input
5
2
fd 100
bk ?
2
fd ?
bk 100
5
fd 100
lt 120
fd ?
lt 120
fd 100
5
fd 100
lt ?
fd 100
lt 120
fd 100
5
fd 100
rt ?
fd 100
rt 120
fd 100
Output
100
100
100
120
120
```

## Solution
My thoughts are, have two robots, one of them follows the program "forwards", up until you have a line containing the `?`.  
The second robot follows the program "backwards", up until you find the `?`.  
If the command before the `?` is `fd` or `bk`, then the answer is the distance between the two robots.  
If the command is `rt` or `lt`, then the answer is the difference in angle between the robots.   

One problem with this is the backwards robot doesn't necessarily need to end with the same rotation. You could brute force it. There are only 20 test cases, each with 1000 lines so `360*20*1000` worst case is only `7,200,000`.

[logo2.cpp](./logo2.cpp)