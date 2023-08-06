# Accounting
- [Problem](#problem)
- [Solution](#bokforing.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/bokforing)

### Description

Erika the economist studies economic inequality. Her model starts in a situation where everybody has the same amount of money. After that, people’s wealth changes in various complicated ways.
Erika needs to run a simulation a large number of times to check if her model works. The simulation consists of `N` people, each of whom begins with `0` kroners. Then `Q` events happen, of three different types: An event of type “SET `i` `x`” means that the `i`th person’s wealth is set to `x`. An event of type “RESTART `x`” means that the simulation is restarted, and everybody’s wealth is set to `x`. An event of type “PRINT `i`” reports the current wealth of the `i`th person. Unfortunately, Erika’s current implementation is very slow; it takes far too much time to keep track of how much money everybody has. She decides to use her algorithmic insights to speed up the simulation.

### Input
The first line includes two integers `N` and `Q`, where `1 <= N <= 10^6` and `1 <= Q <= 2 \cdot 10^5`. The following `Q` lines each start with a string that is either “SET”, “RESTART”, or “PRINT”. There is guaranteed to be at least one event of type “PRINT”.
If the string is “SET” then it is followed by two integers `i` and `x` with `1 <= i <= N` and `0 <= x <= 10^4`. If the string is “RESTART” then it is followed by an integer `x` with `0 <= x <= 10^4`. If the string is “PRINT” then it is followed by an integer `i` with `1 <= i <= N`.

### Output
For each event of type “PRINT”, write the `i`th person’s capital. 

### Examples
```
Input
3 5
SET 1 7
PRINT 1
PRINT 2
RESTART 33
PRINT 1
Output
7
0
33
```
```
Input
5 7
RESTART 5
SET 3 7
PRINT 1
PRINT 2
PRINT 3
PRINT 4
PRINT 5
Output
5
5
7
5
5
```


## Solution
### Using a vector/array
At first I just did what you would assume but shockingly, thats too slow. I don't know how to make it faster. I tried a lot of minor optimisations but this is what I currently got.  

[bokforing.cpp](./bokforing.cpp)

### Using a map
Use a map of person to amount they have. This means you only need to keep track of the people you use since most of the time, you won't set the person manually.  

Then, when you reset, set a default number to use instead and clear the map. If the person is in the map, print that value. Otherwise print the default.  

This is more efficient because the reset memory fill takes a long time.  
This is only more efficient if you aren't going to manually set for each person.

[map.cpp](./map.cpp)

Solved!