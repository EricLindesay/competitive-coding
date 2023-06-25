# Double Cola - 1100
**Tags**: Implementation, Maths  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/82/A)  

Sheldon, Leonard, Penny, Rajesh and Howard are in the queue for a "Double Cola" drink vending machine; there are no other people in the queue. The first one in the queue (Sheldon) buys a can, drinks it and doubles! The resulting two Sheldons go to the end of the queue. Then the next in the queue (Leonard) buys a can, drinks it and gets to the end of the queue as two Leonards, and so on. This process continues ad infinitum.  

For example, Penny drinks the third can of cola and the queue will look like this: Rajesh, Howard, Sheldon, Sheldon, Leonard, Leonard, Penny, Penny.  

Write a program that will print the name of a man who will drink the `*n*`-th can.  

Note that in the very beginning the queue looks like that: Sheldon, Leonard, Penny, Rajesh, Howard. The first person is Sheldon.  
  
### Input
The input data consist of a single integer `*n*` (`1 ≤ *n* ≤ 10`9``).  

It is guaranteed that the pretests check the spelling of all the five names, that is, that they contain all the five possible answers.  
  
### Output
Print the single line — the name of the person who drinks the `*n*`-th can of cola. The cans are numbered starting from 1. Please note that you should spell the names like this: "`Sheldon`", "`Leonard`", "`Penny`", "`Rajesh`", "`Howard`" (without the quotes). In that order precisely the friends are in the queue initially.

### Examples
```
Input
1
Output
Sheldon
```
```
Input
6
Output
Sheldon
```
```
Input
1802
Output
Penny
```


-----
## Solution

### Initial Thoughts
```
5 + 10 + 15 + 20 + 25 + 30
5/2(n)(n+1)

6,
5/2 n**2 + 5/2 n - 6 = 0
n = 1.128, -2.128

17,
5/2 n**2 + 5/2 n - 17 = 0
n = 2.155, -3.155

19
5/2 n**2 + 5/2 n - 19 = 0
n = 2.302, -3.302

15
5/2 n**2 + 5/2 n - 15 = 0
n = 2, -3


So lets find the answer for 17
17 gives 2.155
floor(2.155) = 2
So it is in the SSS section.

So we have already seen. 5/2(2)(2+1) = 15 of them. So we are 17-15 = 2 into the threes section.
Then we can do  2//(2+1) = 0, so it's the Ss


What about 19 now
19 gives 2.302
floor(2.302) = 2
So it is in the triples section

So we've already seen 15 of them. So 19-15 = 4 remain.
Then we can do 4//(2+1) = 4//3 = 1, so it's in the Ls
```
[wrong_answer.cpp](./wrong_answer.cpp)  

### Misread Problem
When testing, I realised that the 1802 answer was incorrect. Even when trying brute force.  
So I reread the question and realised that since it doubles every time, the sizes would be `5, 10, 20, 40 ...`  
```
It goes 5, 10, 20, 40 damnit.  
1, 2, 4, 8, 16, 32  * 5
sum(first n) = 2**n - 1

SLPRH SSLLPPRRHH SSSSLLLLPPPPRRRRHHHH
5 + 10 + 20

5*(2**n - 1) = 19

5*2**n = 24
2**n = 4.8
n = log2 (4.8) = 2
So its in section 2. This aligns with before

5(2**2 - 1) = 15
19-15 = 4 remaining
```
Then we can use the same logic as before to get the answer.  
[double_cola.cpp](./double_cola.cpp)  


Solved!

