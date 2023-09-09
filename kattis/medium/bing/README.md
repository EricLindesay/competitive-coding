# Bing It On
- [Problem](#problem)
- [Solution](#bing.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/bing)

### Description
 Photo by Lindsay Bremner. Bing wants to showcase its clear superiority over Alphabet’s lesser known search engine in the great bing-it challenge of 2016. In order to do this, they have pulled out all the stops and decided to hire the very best of the best of Norwegian engineers to do the work for them. Bing knows that performance is the name of the game when it comes to the world wide web, and because of this they want to make their typeahead is as performant as possible. Your task is to analyze the stream of searches coming in, and let everyone know how many of these searches began with the letters currently in the search bar.

### Input
Each test case begins with a line with a single integer `N`. The following `N` lines each contain one word using only the characters a–z.

### Output
For each word, output an integer representing how many of the previous words began with or were equal to that word.
Limits `1 <= N <= 100, 000` Each word has between `1` and `32` characters. 

### Examples
```
Input

10
histories
adventure
history
his
ad
hi
advent
mouse
cat
his
Output

0
0
0
2
1
3
1
0
0
3
```


## Solution

[bing.cpp](./bing.cpp)

Solved!