# Easy Problem - 1800
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/1096/D)  

Vasya is preparing a contest, and now he has written a statement for an easy problem. The statement is a string of length `n` consisting of lowercase Latin latters. Vasya thinks that the statement can be considered hard if it contains a subsequence `hard`; otherwise the statement is easy. For example, `hard`, `hzazrzd`, `haaaaard` can be considered hard statements, while `har`, `hart` and `drah` are easy statements.   

Vasya doesn't want the statement to be hard. He may remove some characters from the statement in order to make it easy. But, of course, some parts of the statement can be crucial to understanding. Initially the `ambiguity` of the statement is `0`, and removing `i`-th character increases the `ambiguity` by `a_i` (the index of each character is considered as it was in the original statement, so, for example, if you delete character `r` from `hard`, and then character `d`, the index of `d` is still `4` even though you delete it from the string `had`).  

Vasya wants to calculate the minimum `ambiguity` of the statement, if he removes some characters (possibly zero) so that the statement is easy. Help him to do it!  

Recall that subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.  
  
### Input
The first line contains one integer `n` (`1 <= n <= 10^5`) — the length of the statement.  

The second line contains one string `s` of length `n`, consisting of lowercase Latin letters — the statement written by Vasya.  

The third line contains `n` integers `a_1, a_2, ..., a_n` (`1 <= a_i <= 998244353`).  
  
### Output
Print minimum possible `ambiguity` of the statement after Vasya deletes some (possibly zero) characters so the resulting statement is easy.

### Examples
```
Input
6
hhardh
3 2 9 11 7 1
Output
5
```
```
Input
8
hhzarwde
3 2 6 9 4 8 7 1
Output
4
```
```
Input
6
hhaarr
1 2 3 4 5 6
Output
0
```

### Note
In the first example, first two characters are removed so the result is `ardh`.  

In the second example, `5`-th character is removed so the result is `hhzawde`.  

In the third example there's no need to remove anything.


## Solution

### Initial Thoughts
Could do regex to see if `hard` exists but not sure how efficient that would be.  
You keep track of the scores for removing `h`, `a`, `r` and `d`.  
Then you loop through the string, as you find one of those values, increment the required array element by the amount. (hashmap)  
As you loop through, the first time you find an `a`, stop incrementing on `h`, no more `h`s matter.  

This does have a flaw. In the following case:  
```
hahard
10000 1 1 1 1 1
```
You should remove the second `h` but this wouldn't find that.  

So this method only works to see if you should remove the first occurance of any list of characters.  
It will catch `hhhhard` but not `hahard`.  
We could loop through again, storing the secondary occurances.  
You could instead have an array and a counter, if there is a new set of `h`s, add that onto the end of the array.  

In the future, an efficiency improvement *could* be to store a copy of the string, removing all of the values except `hard` and loop through that to find what to remove. You would then have to be able to say which you removed. To reconstruct the list.  
