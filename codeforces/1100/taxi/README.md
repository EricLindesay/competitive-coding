# Taxi - 1100
**Tags**: *special Problem, Greedy, Implementation  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/158/B)  

After the lessons `*n*` groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the `*i*`-th group consists of `*s*`*i*`` friends (`1 ≤ *s*`*i*` ≤ 4`), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?  
  
### Input
The first line contains integer `*n*` (`1 ≤ *n* ≤ 10`5``) — the number of groups of schoolchildren. The second line contains a sequence of integers `*s*`1`, *s*`2`, ..., *s*`*n*`` (`1 ≤ *s*`*i*` ≤ 4`). The integers are separated by a space, `*s*`*i*`` is the number of children in the `*i*`-th group.  
  
### Output
Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.

### Examples
```
Input
51 2 4 3 3
Output
4
```
```
Input
82 3 4 4 2 1 3 1
Output
5
```

### Note
In the first test we can sort the children into four cars like this:  

 - the third group (consisting of four children), 
- the fourth group (consisting of three children), 
- the fifth group (consisting of three children), 
- the first and the second group (consisting of one and two children, correspondingly). 
There are other ways to sort the groups into four cars.


-----
## Solution

### Two Initial Thoughts
You can sort it, loop backwards until you get to a number less than 4, then start looping forward (two pointers) to fill the taxis.  
You can just go through it and see if you can find 4-(number) in the array, if you can find it then you know they must share a taxi perfectly. Otherwise, look for 3-(number) until you either can't find any group which can pair properly or the thing gets filled. Remember, three or more groups can fit in one taxi tho.  
The second option seems like it would also work but would be harder to do, so I implemented the first one.

[taxi.cpp](/taxi.cpp)

Solved!
