# Buttons - 1000
**Tags**: Implementation, Maths  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/268/B)  

Manao is trying to open a rather challenging lock. The lock has `*n*` buttons on it and to open it, you should press the buttons in a certain order to open the lock. When you push some button, it either stays pressed into the lock (that means that you've guessed correctly and pushed the button that goes next in the sequence), or all pressed buttons return to the initial position. When all buttons are pressed into the lock at once, the lock opens.  

Consider an example with three buttons. Let's say that the opening sequence is: {2, 3, 1}. If you first press buttons 1 or 3, the buttons unpress immediately. If you first press button 2, it stays pressed. If you press 1 after 2, all buttons unpress. If you press 3 after 2, buttons 3 and 2 stay pressed. As soon as you've got two pressed buttons, you only need to press button 1 to open the lock.  

Manao doesn't know the opening sequence. But he is really smart and he is going to act in the optimal way. Calculate the number of times he's got to push a button in order to open the lock in the worst-case scenario.  
  
### Input
A single line contains integer `*n*` (`1 ≤ *n* ≤ 2000`) — the number of buttons the lock has.  
  
### Output
In a single line print the number of times Manao has to push a button in the worst-case scenario.

### Examples
```
Input
2
Output
3
```
```
Input
3
Output
7
```

### Note
Consider the first test sample. Manao can fail his first push and push the wrong button. In this case he will already be able to guess the right one with his second push. And his third push will push the second right button. Thus, in the worst-case scenario he will only need 3 pushes.


-----
## Solution

### Initial Thoughts
O(1), constant time.  
The number pressed is `(n-1) + 2*(n-2) + ... + 0  + n`.  
This can be simplified into the form of `an-b`.  
`a` is equivalent to `1+2+3+4 + 1` which is equal to `n(n+1)/2 + 1`.  
`b` is equivalent to `1*1 + 2*2 + ... + n*n` which is equal to `n(n+1)(2n-1)/6`.  

However, we don't want to use n, we want to use n-1.  
This can then directly calculate the answer by substituting it all in.  
If you wanted to get it more efficient, you could simplify the equation. The two equations are all in terms of `n` and would give two cubic sections. You can then simplify it to get one cubic equation which would be faster, but only by a small amount.  
[buttons.cpp](buttons.cpp)  


Solved!