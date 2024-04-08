# Cuckoo! Cuckoo!
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/cuckoocuckoo)

### Description
 The cuckoo bird pops out of the cuckoo clock and sounds off once on the quarter hour, half hour, and three-quarter hour. At the beginning of each hour, it sounds off the hour (1–12). Given the current time and a target number `N`, your task is to determine what time it will be when the cuckoo bird finishes sounding off `N` times. If the cuckoo bird would be sounding off at the starting time, include those sounds in the count. If the count is reached on the hour, report the time at the start of that hour. That is, you may assume the cuckoo finishes sounding off before the minute is up.

### Input
The input consists of 2 lines. The first line contains the current time in the form HH:MM where `1 <= \texttt{HH} <= 12` and `0 <= \texttt{MM} <= 59`, with leading 0’s if necessary. The second line contains a single integer representing the target number `N` such that `1 <= N <= 200`.

### Output
Print the time at which the cuckoo bird has sounded off `N` times. The time should be printed in the same format as the input. 

### Examples
```
Input
02:36
1
Output
02:45
```
```
Input
12:00
13
Output
12:15
```
```
Input
11:00
30
Output
01:00
```
```
Input
02:36
1
Output
02:45
```
```
Input
12:00
13
Output
12:15
```
```
Input
11:00
30
Output
01:00
```


## Solution

[cuckoocuckoo.cpp](./cuckoocuckoo.cpp)
