# Yet Another Yet Another Task

- [Problem](#Problem)
- [Solution](#Solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1359/D)

Alice and Bob are playing yet another card game. This time the rules are the following. There are `n` cards lying in a row in front of them. The `i-th` card has value `ai`.

First, Alice chooses a non-empty consecutive segment of cards `[l;r] (l≤r)`. After that Bob removes a single card `j` from that segment `(l≤j≤r)`. The score of the game is the total value of the remaining cards on the segment `(al+al+1+⋯+aj−1+aj+1+⋯+ar−1+ar)`. In particular, if Alice chooses a segment with just one element, then the score after Bob removes the only card is 0.

Alice wants to make the score as big as possible. Bob takes such a card that the score is as small as possible.

What segment should Alice choose so that the score is maximum possible? Output the maximum score.

**Input**
- The first line contains a single integer `n (1≤n≤105)` — the number of cards.
- The second line contains `n` integers `a1,a2,…,an (−30≤ai≤30)` — the values on the cards.

**Output**  
Print a single integer — the final score of the game.

*Examples*

```
input
5
5 -2 10 -1 4
output
6
```
```
input
8
5 2 5 3 -30 -30 6 9
output
10
```
```
input
3
-10 6 -15
output
0
```
*Note*  
In the first example Alice chooses a segment [1;5] — the entire row of cards. Bob removes card 3 with the value 10 from the segment. Thus, the final score is 5+(−2)+(−1)+4=6.

In the second example Alice chooses a segment [1;4], so that Bob removes either card 1 or 3 with the value 5, making the answer 5+2+3=10.

In the third example Alice can choose any of the segments of length 1: [1;1], [2;2] or [3;3]. Bob removes the only card, so the score is 0. If Alice chooses some other segment then the answer will be less than 0.


## Solution

To increase the efficiency of finding the score of a segment, if you keep track of the highest value, you know that Bob will remove that so you don't need to add it to the score.  
If you then meet a new value which is higher than the current, increase the sum by the previous highest value and store the new highest value.  

### Brute Force
This method goes through every possible segment, finding the score for each and then picking the highest.  
A slight improvement made to this is that you never start or end on a negative because the best segment is never going to be there.  
O(n^3) time. This is obviously too slow.  
- Go through main list once to find start pos.  
- Go through main list again to find end pos.  
- Go through the segment produced by those values to find the sum.  
[brute_force.cpp](solutions/brute_force.cpp)

### Accumulating Sum
This is just an obvious improvement to the brute force method that I should have seen sooner. The previous method loops through each segment again however this is not necessary as long as you keep a 'rolling sum' and you keep track of the highest value.  
[accumulate.cpp](solutions/accumulate.cpp)

### Thoughts
#### Two Pointers
Use two pointers, one at the start of the list, one at the end.  
```
if (left_pointer+1 == score_increase):
    left_pointer++;
if (right_pointer-1 == score_increase):
    right_pointer--;
```
This doesn't work because if you have a list `1 2 3 -199 1 1`, moving either of the pointers by one decreases the score so we don't do that. However, the optimal score from that list would be `1 2 3`.  

Obviously just have an increasing counter. No need to loop back through the segment.  


