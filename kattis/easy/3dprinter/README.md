# 3dprinter
- [Problem](#problem)
- [Solution](#3dprinter.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/3dprinter)

### Description
You have a single 3D printer, and would like to use it to produce `n` statues. However, printing the statues one by one on the 3D printer takes a long time, so it may be more time-efficient to first use the 3D printer to print a new printer. That new printer may then in turn be used to print statues or even more printers. Print jobs take a full day, and every day you can choose for each printer in your possession to have it print a statue, or to have it 3D print a new printer (which becomes available for use the next day).

What is the minimum possible number of days needed to print at least `n` statues?

### Input
The input contains a single integer `n (1 <= n <= 10000)`, the number of statues you need to print.

### Output
Output a single integer, the minimum number of days needed to print at least `n` statues.

### Examples
```
Input
1
Output
1
```
```
Input
5
Output
4
```

## Solution

Treat this as a change giving problem.  
Store an array representing how many days it requires to get to the `i`th item. So `days[2]` is how many days it takes to produce 2 items.  
First we start with 1 printer. Go through this array and update how long it takes to print up to `t` items using a single printer.  
But what if we printed a printer the first day instead? Well, start the for loop to update the days, but set the lower bound to be how many printers you have.  
We do this as many times as possible, until the number of printers * 2 exceed the number of items we need to create. 

I think there is some logic you can do with `num printers = 2^day`, you want to print only printers until you get to the day where you can print the value you want so the result is `day + 1`.

[3dprinter.cpp](./3dprinter.cpp)

Solved!