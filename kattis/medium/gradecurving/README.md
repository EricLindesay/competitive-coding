# Grade Curving
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/gradecurving)

### Description
 An instructor may use curved score to grade a student’s performance. Assume a student’s original score is `x` out of a total of `100`. One of the curving methods is to apply to `x` the curving function `f(x) = 10\sqrt {x}`. The function may be applied `k >= 0` times. For better score readability, the result is rounded to the next integer and the final curved score is `y = \lceil f^ k(x) \rceil `. For example, if the curving function is applied `k = 3` times to `x = 80`, it changes the score to\begin{align*} f^3(80) & = f^2(f(80)) = f^2(89.4427) \\ & = f(f(89.4427)) = f(94.5742) = 97.2492. \end{align*}
So the curved score is `y = \lceil 97.2492 \rceil = 98`.
John wants to curve a student’s score `x` using this method so that the curved score `y` is between `y_{low}` and `y_{high}`. How many times should he apply the curving function? In particular, what are the minimum and maximum choices of `k`, so that `y_{low} <= y <= y_{high}`?

### Input
The input has a single line with three integers: `x`, `y_{low}`, and `y_{high}` (`1 <= x <= y_{low} <= y_{high} <= 100`).

### Output
Output the minimum and maximum possible choices of `k`. If the curving function can be applied an infinite number of times, output “inf” for the maximum. If there is no `k` that meets the curving requirement, output a single word “impossible”. 

### Examples
```
Input

80 85 98
Output

1 3
```
```
Input

98 98 100
Output

0 inf
```
```
Input

80 85 89
Output

impossible
```
```
Input

80 85 98
Output

1 3
```
```
Input

98 98 100
Output

0 inf
```
```
Input

80 85 89
Output

impossible
```


## Solution

For this, you just simulate the curving method.  
You know the answer should be "inf" for high if high is 100 and you don't start at 100.

You know the problem is impossible if, on the first loop, you skip entirely over the lower bound and upper bound.
If `X_i < low && X_{i+1} > high`.  

[gradecurving.cpp](./gradecurving.cpp)

Solved!

Solved during the University of Nottingham coding competition.