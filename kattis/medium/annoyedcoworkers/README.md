# annoyedcoworkers
- [Problem](#problem)
- [Solution](#annoyedcoworkers.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/annoyedcoworkers)

### Description
It’s another day in the office, and you’re a mastermind of not doing any work yourself. Instead, you’ll go to your coworkers for “help,” but secretly have them do all the work.

You’ve determined that the more one of your coworkers helps you, the more annoyed they become. You’ve also been able to determine how much more annoyed a coworker gets everytime you ask them for help. At the beginning of the day, a coworker is initially `a` annoyed at you. That’s their annoyance level. Everytime you ask them for help though, they become `d` more annoyed at you – their annoyance level `a` increases by a constant amount `d` so that `a = a + d   `.

You want to complete a project of `h` tasks solely with “help” from your coworkers, but you need to be careful not to annoy any of them too much.

What’s the best you can do?

### Input
The first line contains integers `h` and `c`, where `h (1 <= h <= 100000)` is the number of times you have to ask for help to complete the project, and `c (1 <= c <= 100000)` denotes the number of coworkers you have.

Each of the following `c` lines contains two positive integers `a` and `d`, representing a coworker whose initial annoyance level is `a` and who is getting more annoyed at you by an increase of `d` every time you ask them for help `1 <= a, d <= 10^9`.

### Output
Output a single number, which is the maximum annoyance level any coworker has at you provided you use an optimal strategy to minimize this level. (In other words, of all possible strategies, choose one that minimizes the annoyance level of the worker or workers who are most annoyed at you at the end.)

### Examples
```
Input
4 4
1 2
2 3
3 4
4 5
Output
7
```
```
Input
3 2
1 1000
1000 1
Output
1002
```
```
Input
5 2
1 1
2 2
Output
5
```

## Solution
Use a priority queue, storing a pair containing `a` and `d`. Then sort it based on a custom comparator, which sorts based on `a+d` in ascending order. Then just pop from this queue, increment the highest annoyance and then push the newly annoyed coworker back onto the queue.

[annoyedcoworkers.cpp](./annoyedcoworkers.cpp)

Solved!