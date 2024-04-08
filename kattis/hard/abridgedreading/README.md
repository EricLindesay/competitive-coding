# Abridged Reading
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/abridgedreading)

### Description

Miss Othmar is a grade school teacher who uses a very interesting textbook in her science class. All of the chapters in the book have material that depends on at most one previous chapter’s material, while several chapters are labeled “Culminating Concept” chapters that have no chapters depending on them –– they basically represent the culmination of the stream of material in all the previous chapters that must be read before them. Chapters that are not Culminating Concept chapters are referred to as “prerequisite chapters.”
Because of various delays caused by the pandemic, Miss Othmar is far behind where she wants to be in the class. It’s too late to try to cover all of the Culminating Concept chapters in the book (and their required prerequisite chapters) so she has decided to cover just two more Culminating Concept chapters. To give the kids a break she has decided to pick the two Culminating Concept chapters which require the least amount of reading –– this would include not only those chapters but their prerequisite chapters as well.

### Input
Input starts with a line containing two integers `n` `m` where `n` (`2 <= n <= 1, 000`) indicates the number of chapters (numbered `1` to `n`) and `m` (`0 <= m < n`) indicates the number of chapter dependencies. After this are `n` positive values indicating the number of pages in each chapter. These values will be on one or more lines and the number of pages in any chapter is ` <= 1, 000`. After this are `m` lines each containing two integers `a` `b` `(1 <= a < b <= n)` indicating that chapter `a` must be read before chapter `b`. No chapter appears as the second integer in these lines more than once. There will be at least two Culminating Concept chapters.

### Output
Output the minimum number of pages that need to be read in order to complete two Culminating Concept chapters. 

### Examples
```
Input
7 6
10 9 6 4 2 10 12
1 2
1 3
2 4
2 5
3 6
3 7
Output
25
```
```
Input
4 2
10 7 4 6
1 4
2 3
Output
27
```
```
Input
7 6
10 9 6 4 2 10 12
1 2
1 3
2 4
2 5
3 6
3 7
Output
25
```
```
Input
4 2
10 7 4 6
1 4
2 3
Output
27
```


## Solution

[abridgedreading.cpp](./abridgedreading.cpp)