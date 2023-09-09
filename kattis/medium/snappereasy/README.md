# Snapper Chain (Easy)
- [Problem](#problem)
- [Solution](#snappereasy.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/snappereasy)

### Description

Note that this is an easier version of the problem snapperhard
The Snapper is a clever little device that, on one side, plugs its input plug into an output socket, and, on the other side, exposes an output socket for plugging in a light or other device.
When a Snapper is in the ON state and is receiving power from its input plug, then the device connected to its output socket is receiving power as well. When you snap your fingers – making a clicking sound – any Snapper receiving power at the time of the snap toggles between the ON and OFF states.
In hopes of destroying the universe by means of a singularity, I have purchased `N` Snapper devices and chained them together by plugging the first one into a power socket, the second one into the first one, and so on. The light is plugged into the `N`th Snapper.
Initially, all the Snappers are in the OFF state, so only the first one is receiving power from the socket, and the light is off. I snap my fingers once, which toggles the first Snapper into the ON state and gives power to the second one. I snap my fingers again, which toggles both Snappers and then promptly cuts power off from the second one, leaving it in the ON state, but with no power. I snap my fingers the third time, which toggles the first Snapper again and gives power to the second one. Now both Snappers are in the ON state, and if my light is plugged into the second Snapper it will be on.
I keep doing this for hours. Will the light be on or off after I have snapped my fingers `K` times? The light is on if and only if it’s receiving power from the Snapper it’s plugged into.

### Input
The first line of the input gives the number of test cases, `T`. `T` lines follow. Each one contains two integers, `N` and `K`.
You may assume that `1 <= T <= 10, 000`, `1 <= N <= 10` and `0 <= K <= 100`.

### Output
For each test case, output one line containing “Case #`x`: `y`”, where `x` is the case number (starting from 1) and `y` is either "ON" or "OFF", indicating the state of the light bulb. 

### Examples
```
Input

4
1 0
1 1
4 0
4 47
Output

Case #1: OFF
Case #2: ON
Case #3: OFF
Case #4: ON
```


## Solution
This is done by thinking of the chain as just a binary number.  
For example, for the input `4 47` you can represent the chain as:
```
0000  // initial position
0001  // one snap
0010  // two snaps
```

You should accept the number of snaps, if the final number is `1111` (they are all on).
So, what you do is you do `47 % 16 = 15` (this is because if you reach `1111` and snap again, it resets the cycle).  
And you see if this number has all 1s in binary, which it does (this can be done by seeing if `15 == 16 - 1`).  

So, more generally, if `k % maxSnaps == maxSnaps - 1` print ON, otherwise, print OFF.

[snappereasy.cpp](./snappereasy.cpp)

Solved!

This is also good enough for the [hard version](../../easy/snapperhard/README.md)