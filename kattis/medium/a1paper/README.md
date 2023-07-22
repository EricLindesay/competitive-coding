# A1 Paper
- [Problem](#problem)
- [Solution](#a1paper.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/a1paper)

### Description
Björn likes the square root of two, `\sqrt {2} = 1.41421356\dots ` verymuch. He likes it so much that he has decided to write down thefirst `10, 000` digits ofit on a single paper. He started doing this on an A4 paper, butran out of space after writing down only `1250` digits. Being pretty good atmath, he quickly figured out that he needs an A1 paper to fitall the digits. Björn doesn’t have an A1 paper, but he hassmaller papers which he can tape together.
Taping two A2 papers together along their long side turnsthem into an A1 paper, two A3 papers give an A2 paper, and soon. Given the number of papers of different sizes that Björnhas, can you figure out how much tape he needs to make an A1paper? Assume that the length of tape needed to join togethertwo sheets of papers is equal to their long side. An A2 paperis `2^{-5/4}` metersby `2^{-3/4}` metersand each consecutive paper size (A3, A4, ) have the same shapebut half the area of the previous one.

### Input
The first line of input contains a single integer`2<= n <= 30`, theA-size of the smallest papers Björn has. The second linecontains `n-1` integersgiving the number of sheets he has of each paper size startingwith A2 and ending with A`n`. Björn doesn’t have more than`10^9` sheets of any papersize.

### Output
If Björn has enough paper to make an A1 paper, output asingle floating point number, the smallest total length of tapeneeded in meters. Otherwise output “impossible”. The output number should have anabsolute error of at most `10^{-5}`.

### Examples
```
Input
4
1 0 5
Output
1.60965532263
```
```
Input
3
0 3
Output
impossible
```


## Solution
You can actually do this entire problem while reading in the input.  

Represent the number of pages as a multiple of the smallest page. E.g. in the example `4\n1 0 5`, you have `1 A2` page which is equivalent to `4 A4` pages and `5 A4` pages which means you have `11 A4` pages total. 

The minimum number of pages needed is `2^{n-1}`. For the previous example, you need `8 A4` pages total to make the A1. Using this you can work out whether a solution is possible or not.

To find the minimum tape size:
At first, I thought: "You need to find out how many of the smallest you need to merge and then using that, merge up until you get to A2 pages". However, while this is true, it isn't necessary. You know, if you have `1 A2` page, eventually you will have to use enough tape to form another `A2` page. If you don't have enough pages to do this merge then don't worry, you will catch that in the `impossible` case. Then, if you will eventually need `4 A3` pages, you know you need `4` amounts of `A3` tape.

Using this, you can compute how much tape you need while you read in the input. Then you also need to add on the amount of tape for an `A2 -> A1` merge and you are done.  

[a1paper.cpp](./a1paper.cpp)

### Optimisation
The program above is fast enough to solve it however I noticed some small optimisations I could do, so I did them. 

I did the following changes:
- Removed the unnecessary `sizes` vector, making it more memory efficient (from O(n) to O(1)).
    - Also then changed how the loop worked to accommodate this.
- Added a break if you have enough pages
    - If you have enough pages, then you don't need to loop through the rest of the input, you can just stop right there. For example `4\n 2 0 19`, in this case, you can stop looping as soon as you see that you have the `2 A2` pages.
- Replace a `pow(2, n-i-1)` with `1 << (n-i-1)`. Doing a binary left shift is faster than a power. The compile probably would optimise the power into a left shift anyway, but doing it manually as well won't hurt.

[optimised.cpp](./optimised.cpp)

Solved!