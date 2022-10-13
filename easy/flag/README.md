# Flag - 800
**Tags**: Implementation  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/16/A)  

According to a new ISO standard, a flag of every country should have a chequered field `*n* × *m*`, each square should be of one of 10 colours, and the flag should be «striped»: each horizontal row of the flag should contain squares of the same colour, and the colours of adjacent horizontal rows should be different. Berland's government asked you to find out whether their flag meets the new ISO standard.  
  
### Input
The first line of the input contains numbers `*n*` and `*m*` (`1 ≤ *n*, *m* ≤ 100`), `*n*` — the amount of rows, `*m*` — the amount of columns on the flag of Berland. Then there follows the description of the flag: each of the following `*n*` lines contain `*m*` characters. Each character is a digit between `0` and `9`, and stands for the colour of the corresponding square.  
  
### Output
Output `YES`, if the flag meets the new ISO standard, and `NO` otherwise.

### Examples
```
Input
3 3000111222
Output
YES
```
```
Input
3 3000000111
Output
NO
```
```
Input
3 3000111002
Output
NO
```


-----
## Solution

### Initial Thoughts
Just look at each row and keep track of the colours. See if they are different or not. Just do what you would expect.  

[flag.cpp](/flag.cpp)  

Solved!
