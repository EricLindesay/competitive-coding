# A Favourable Ending
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/favourable)

### Description

Fiction books are all the same. The author has decided everything in advance, from beginning, middle, to the final plot. You, the reader, just read from page 1 to the very last page, in that order. So predictable.
A choose-your-own-story fiction book is different. The book is divided into sections. Each section starts on a new page. At the end of each section, you as the reader gets a choice of how you want the story to continue. You get to choose among a set of options such as “If you want to enter the dark dungeon, go to page 37. If you want to drink the spoiled potion, go to page 221. If you want to befriend the three-eyed scorpion, go to page 114.” In this case, there are three choices, and you choose one of these by flipping over to that page. A new section starts on that page, and you read that next. You continue to do so until, eventually, you reach a section that ends the story. A story can end in one of two ways: either favourably or catastrophically. As the true computer scientist you are, you wonder how many distinct favourable stories a book contains. You are given a choose-your-own-story book, and you want to compute the number of times you can read the book, without ever reading the exact same story again, and each time ending in a favourable way. We will assume that each section that ends with a choice, always ends with exactly three choices. We will also assume that no story contains a loop; there are no infinite stories. You always start your choose-your-own-story on page 1. 

### Input
The first line of the input contains an integer, `T`, the number of test cases (`1 <= T <= 100`). The first line of each test case contains an integer `S`, the number of sections (`1 <= S <= 100`).
Each of the next `S` lines contains either exactly four integers, or one integer plus the word “favourably” or “catastrophically”. All integers are between `1` and `400`. The first integer on each of `S` lines is the page number on which that section begins. The next three integers are the page numbers on which each of the three sections start, among which we choose one. The three page numbers are distinct, and there is always a section starting on those three page numbers. Alternatively, the next word is either “favourably” or “catastrophically”, which means the story ends here, and in that way. It is guaranteed that some section begins on page 1 and no two sections begin on the same page number.
All sections listed in the input can be reached starting at page `1`.

### Output
For each of the `T` test cases, output the number of distinct stories that end in a favourable ending. The answer is guaranteed not to exceed a signed `64`-bit integer. 

### Examples
```
Input
2
4
1 3 11 13
3 favourably
11 catastrophically
13 favourably
10
1 21 6 17
3 favourably
6 catastrophically
8 favourably
12 favourably
15 6 33 12
17 15 8 33
21 3 29 15
29 favourably
33 catastrophically
Output
2
5
```
```
Input
2
4
1 3 11 13
3 favourably
11 catastrophically
13 favourably
10
1 21 6 17
3 favourably
6 catastrophically
8 favourably
12 favourably
15 6 33 12
17 15 8 33
21 3 29 15
29 favourably
33 catastrophically
Output
2
5
```


## Solution

[favourable.cpp](./favourable.cpp)

Solved!