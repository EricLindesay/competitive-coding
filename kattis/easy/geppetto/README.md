# Geppetto
- [Problem](#problem)
- [Solution](#geppetto.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/geppetto)

### Description

Everyone’s favorite character and puppet-maker Geppetto has opened a new pizza place, the best in town. Geppetto is trying to make the best pizza possible, but at the same time he doesn’t want to have a small selection of pizzas.
He makes his pizzas out of `N` ingredients marked with numbers from `1` to `N`. All that would be simple if he could mix any ingredient with every ingredient on the pizza, but unfortunately, that is not the case. Sometimes some ingredients cannot mix and that creates additional complications for our pizza master.
There are `M` pairs of ingredients that cannot be on the same pizza at the same time. Given these restrictions, Geppetto wants to know how many different pizzas he can make. Help him answer this question. Two pizzas are considered different if there is an ingredient of index `i` that is on one pizza, but not on the other.

### Input
The first line of input contains two integers `N` and `M` (`1 <= N <= 20`, `0 <= M <= 400`). Each of the following `M` lines contains two different numbers `a` and `b`, they represent the prohibition of mixing ingredients marked with `a` and `b` on the pizza. (`1 <= a, b <= N`). All pairs of ingredients are not necessarily distinct, some pair could occur multiple times.

### Output
The first and only line of output must contain the number of different pizzas given the restrictions in the task. 

### Examples
```
Input
3 2
1 2
2 3

Output
5
```
```
Input
3 0

Output
8
```
```
Input
3 3
1 2
1 3
2 3

Output
4
```


## Solution
N = 1
P = 1

N = 2
P = 1, 2, 1-2 = 3

N = 3
P = 1, 2, 3, 1-2, 2-3, 1-3, 1-2-3 = 

N = 4
P = 1, 2, 3, 4, 1-2, 1-3, 1-4, 2-3, 2-4, 3-4, 1-2-3, 1-2-4, 1-3-4, 2-3-4, 1-2-3-4 = 


[geppetto.cpp](./geppetto.cpp)