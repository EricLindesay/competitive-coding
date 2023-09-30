# Min Cost Climbing Stairs
- [Problem](#problem)
- [Solution](#min-cost-climbing-stairs.cpp)

## Problem
[Problem link](problem_link)

### Description
You are given an integer array `cost` where `cost[i]` is the cost of `i^th` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return *the minimum cost to reach the top of the floor*.

### Input


- `2 <= cost.length <= 1000`
- `0 <= cost[i] <= 999`




### Examples
```
Input: cost = [10,<u>15</u>,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
```

```
Input: cost = [<u>1</u>,100,<u>1</u>,1,<u>1</u>,100,<u>1</u>,<u>1</u>,100,<u>1</u>]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```


## Solution
Have an array storing how expensive it is to get to this cell.
The array should have two more one more cell than `cost` and should start with 0.  
Then, loop through cost and work out what ans[i+1] and ans[i+2] would be, if they are better then put them in, otherwise keep the old value.

[min-cost-climbing-stairs.cpp](./min-cost-climbing-stairs.cpp)

Solved!

### Further thoughts
You could probably make this memory of O(1) instead of O(n) by keeping the running total in the cost array instead. And then just store the necessary information in a few variables.