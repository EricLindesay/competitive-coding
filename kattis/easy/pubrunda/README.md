# Pub Crawl
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/pubrunda)

### Description

Fritjof is going to his first ever pub crawl. Since he doesn’t want to go all out on his very first time, he’s decided that he’s only going to visit a single pub. As he likes all pubs equally much he will stay at the pub for an equal amount of time regardless of which pub it is. To still be able to brag about the amount of time he’s been on the pub crawl, he wants to visit the pub with the longest queue time. Which pub should Fritjof go to?

### Input
The first line of input contains an integer `N` (`1 <= N <= 10^5`), the number of pubs Fritjof can choose between. The `i`th of the following `N` lines contains the name of the `i`th pub `p_ i`, the number of people in the queue `k_ i` (`0 <= k_ i <= 10^4`) and the integer time `t_ i` it takes for each person to get in (`1 <= t_ i <= 10^4`).
Each `p_ i` is between `1` and `10` characters long and only consists of lowercase and uppercase alphabetical characters (a-z and A-Z). All pub names are unique.

### Output
Print one line with the name of the pub with the longest queue time and the total time it would take for Fritjof to enter the pub. If there are multiple pubs with the same queue time, print the first suitable pub in the list.
Explanation of Sample 1
The last two people in the queues for Gasquen and JAPripps will both enter at time `100`. But it would then take an additional `5` and `20` minutes until Fritjof could enter the pubs if he stood in their respective queues. To maximize the time spent queuing, Fritjof should queue for JAPripps for a total of `120` minutes. 

### Examples
```
Input
3
Basen 10 5
Gasquen 20 5
JAPripps 5 20
Output
JAPripps 120
```
```
Input
5
Basen 5 8
Focus 20 7
Gasqutva 13 21
Kajsabaren 9999 10
Hubben 22 11
Output
Kajsabaren 100000
```
```
Input
3
Basen 10 5
Gasquen 20 5
JAPripps 5 20
Output
JAPripps 120
```
```
Input
5
Basen 5 8
Focus 20 7
Gasqutva 13 21
Kajsabaren 9999 10
Hubben 22 11
Output
Kajsabaren 100000
```


## Solution

[pubrunda/src/main.rs](./pubrunda/src/main.rs)

Solved!