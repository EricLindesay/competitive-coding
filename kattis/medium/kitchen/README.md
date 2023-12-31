# Kitchen Measurements
- [Problem](#problem)
- [Solution](#kitchen.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/kitchen)

### Description

You are making a recipe and need to measure a precise volume of liquid. There are an assortment of cups of varying volumes in your kitchen, however no cup has any markings on it other than to indicate its total volume, and none of them match the volume that you want. You start with the biggest cup full of liquid and, to make sure you know precisely how much volume you are working with at any point in time, you consider steps in which you pour from any nonempty cup into another cup, always pouring until either the cup you are pouring into becomes full, or the cup you are pouring from becomes empty (whichever occurs first). As a simple example, assume you start with a full cup having capacity `5`, and you have another cup with capacity `2`, but your goal is to have `3` units of the liquid in the largest cup. In this case, you can start pouring from the larger cup to the smaller, stopping when the smaller one reaches its capacity of `2`. This will leave precisely `3` units in the larger cup. See Figure 1(a). (1.a) (1.b) (1.c) Figure 1: Pouring between cups As another example, consider a case in which you have `4` cups with capacities `9`, `6`, `3`, and `2`, and you start with the largest cup full, the rest empty, and a goal of ending with `8` units in the largest cup. For ease of discussion we will refer to the cup with capacity `9` as the “`9`-cup” and similarly for the other sizes. You notice that the `6`-cup and `2`-cup have combined capacity of `8`, and so you could pour from the original `9`-cup to fill those two cups, then dump the remaining `1` unit from the `9`-cup into the `3`-cup, and finally pour the full `6`-cup and `2`-cup back into the `9`-cup. See Figure 1(b). In implementing this strategy, the total volume of liquid poured would be `6+2+1+6+2=17`. You could achieve this goal in another way: pour `3` units from the `9`-cup to the `3`-cup (leaving `6` units in the `9`-cup), then fill the `2`-cup from the `3`-cup (leaving `1` unit in the `2` cup), and finally pour the full `2`-cup back into the `9`-cup, resulting in exactly `8` units in that cup. With this strategy, the total volume poured is only `3+2+2=7`. See Figure 1(c).
As a final example, you start with cups of capacities `11`, `10`, `7`, `4`, and `2`, with the `11`-cup full, and a goal of ending up with `10` units in the `11`-cup. Obviously, you could fill the `10`-cup, dump the remaining `1` unit into another cup, and then pour from the full `10`-cup back into the `11`-cup, as illustrated in Figure 2(a). These three pours would mean transferring a total volume of `10+1+10=21`. Figure 2(b) shows a sequence with more steps, but less liquid poured. (2.a) (2.b) Figure 2: More pouring 

### Input
The input consists of a single line of positive integers: `n` `c_1` `c_2` `... ` `c_ n` `V`, where there are `n` cups, with `2 <= n <= 5`, having capacities satisfying ` 64 >= c_1>c_2> ... > c_ n >= 1`. The value `V < c_1` designates the desired volume. You must start with largest cup (that with capacity `c_1`) full of liquid and the other cups empty, and the goal is to get exactly volume `V` into the largest cup.

### Output
Output the minimum amount of liquid that must be poured to achieve the goal, or output impossible if the goal cannot be achieved. 

### Examples
```
Input

2 5 2 3
Output

2
```
```
Input

4 9 6 3 2 8
Output

7
```
```
Input

5 11 10 7 4 2 10
Output

19
```
```
Input

2 5 2 4
Output

impossible
```
```
Input

5 64 45 41 28 2 63
Output

121
```


## Solution

[kitchen.cpp](./kitchen.cpp)