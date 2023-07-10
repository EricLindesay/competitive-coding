# goodmorning
- [Problem](#problem)
- [Solution](#goodmorning.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/goodmorning?tab=metadata)

### Description
Good morning! This is your 5am wake-up call! A partly cloudy day is expected with light rain coming afternoon…

You have just woken up. You desperately need coffee… and… more coffee… and some cereal. And your clothes. And coffee.

To prepare warm cereal, you put some milk into a microwave, trying to heat it for `k` seconds. You must enter `k` on the microwave keyboard.

EXAMPLE DIAGRAM ON PAGE

As you still haven’t had your coffee, your hand (along with eyes and brain) keeps falling down. You are only able to enter a number if your hand would only move downwards and/or to the right. You cannot go back left, nor move your hand up, though you can press the same key again. And again…and again…

For example, you can enter the number `180` or `49`, but not `98` or `132`. Enter a number that is as close to `k` as possible. If there are two solutions, enter any one of them. You are too sleepy to actually care. And you need coffee.

### Input
The first line of input contains the number of test cases `T (1 <= T <= 200)`. The descriptions of the test cases follow:

Each test case consists of one line containing an integer
`k (1 <= k <= 200)`.

### Output
For each test case, output a number that is closest `k` to which can be entered on the keyboard.

### Examples
```
Input
3
180
83
132
Output
180
80
133
```

## Solution

For this one, I first created a `vector<vector<int>>` containing all possible key presses from the current number (which is the index).  
Then, I just loop through these values for 1 digit long numbers, 2 digit long numbers and 3 digit long numbers and find which number is the closest.  

To optimise this, I could have something which says `if (generatedNumber == targetNumber) print number, stop looping`.  
I could also have something which stores previous values generated to reduce repetition, for my code, if it is given `180, 180` then it will manually calculate the answer each time but it should only calculate it once and store the result.  

I knew this problem was bruteforceable due to the low integer requirements `1 <= k <= 200` and abused that knowledge when creating my solution.  

Something to make it even better, because of the limits of T <= 200 and k <= 200, it is highly likely that there will be a test case which does all numbers from 1 -> 200. So you could just generate all of the 1 -> 200, save it in an array and do lookup for each individual value.

[goodmorning.cpp](./goodmorning.cpp)

Solved!