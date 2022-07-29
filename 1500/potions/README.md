#  Potions (Easy Version) - 1500
**Tags**: Brute Force, Data Structures, Dynamic Programming, Greedy
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1526/C1)  

`This is the easy version of the problem. The only difference is that in this version n <= 2000`  

There are `n` potions in a line, with potion `1` on the far left and potion `n` on the far right. Each potion will increase your health by `a_i` when drunk. `a_i` can be negative, meaning that potion will decrease will health.  

You start with `0` health and you will walk from left to right, from first potion to the last one. At each potion, you may choose to drink it or ignore it. `You must ensure that your health is always non-negative`.  

What is the largest number of potions you can drink?  
  
### Input
The first line contains a single integer `n` (`1 <= n <= 2000`) — the number of potions.   

The next line contains `n` integers `a_1`, `a_2`, ... ,`a_n` (`-10^9 <= a_i <= 10^9`) which represent the change in health after drinking that potion.  
  
### Output
Output a single integer, the maximum number of potions you can drink without your health becoming negative.

### Examples
```
Input
6
4 -4 1 -3 1 -3
Output
5
```

### Note
For the sample, you can drink `5` potions by taking potions `1`, `3`, `4`, `5` and `6`. It is not possible to drink all `6` potions because your health will go negative at some point


## Solution

### Two Scenarios
At first glance, all you have to do is loop through the list once, adding to your health total the value. If the potion is negative and you have enough health, drink it.  
However, this doesn't work because what if you drink a `-10` potion and then ten `-1` potions follow it, you should drink the `-1` potions instead.  
A solution to this is to loop through until you find a negative (which you can drink), then split into two scenarios, one where you drink the potion and one you don't. Then see which scenario gives you the most points.  
I know this one will be too slow, so won't submit it. When trying with test data, it is too slow for n=2000.  
[two_scenarios.cpp](solutions/two_scenarios.cpp)  

### Forward Scan
You could also try to do a forward scan, and see how many you lose out on. Then you stop this scan after you reach the -10 being replenished? This idea is still quite vague.  
```
11 -10 -1 -1 -1 -1 10 -1 5 -1000
```
No, this doesn't work.  
In the following scenario, you should never take the -2, but this method would.  
```
2 -2 3 -1 -1 -1 -1 -1
```

### Store Negative Potions
Create a list of potions which give a negative value (as you find them).  
If the current negative will kill you but is weaker than the negatives you already have, replace the previous potion and drink the new one instead. So increment your health by the difference between them.  
If the potion won't kill you, drink it and add it to the list of seen potions.  
If the potion is positive, drink it.  
```
If the potion is negative:
    If it will kill you:
        If this potion is weaker than others drunk:
            replace that in the array of seen bad potions
        else:
            don't drink it
    else:
        drink it and add it to the list
else:
    drink it
```
This is significantly faster than the other method (thanks Indra) but it fails the time limit on test 2 for some reason.  

[track_seen.cpp](solutions/track_seen.cpp)

### Using Lists
In C++, (linked) lists are very useful for inserting and removing elements (which I am doing a lot of).  
The following two programs use a bi-directional list and a forward list respectively.  
The forward list is more efficient.  
[lists.cpp](solutions/lists.cpp)  
[forlists.cpp](solutions/forlists.cpp)  


## Things for Next Time
Always think about creating a new list to store necessary data for when you have to loop through data.  
ALWAYS think about what data structure to use. Originally I was using a vector which was too slow but as soon as I swapped to a forward list, it was efficient enough. This is because the vector has to move about a bunch of memory when inserting but a forward list just points to the new insert position.  


Solved!
