# Maximum Rounding
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://codeforces.com/contest/1857/problem/B)

### Description
Given a natural number x. You can perform the following operation:
- choose a positive integer k and round x to the k-th digit 

Note that the positions are numbered from right to left, starting from zero. If the number has k
digits, it is considered that the digit at the k-th position is equal to 0.

The rounding is done as follows:
- if the digit at the (k−1) -th position is greater than or equal to 5, then the digit at the k-th position is increased by 1, otherwise the digit at the k
-th position remains unchanged (mathematical rounding is used).
- if before the operations the digit at the k-th position was 9, and it should be increased by 1, then we search for the least position k′ (k′>k), where the digit at the k′-th position is less than 9 and add 1 to the digit at the k′-th position. Then we assign k=k′.
- after that, all digits which positions are less than k are replaced with zeros.

Your task is to make x as large as possible, if you can perform the operation as many times as you want.

For example, if x is equal to 3451, then if you choose consecutively:
- k=1, then after the operation x will become 3450
- k=2, then after the operation x will become 3500
- k=3, then after the operation x will become 4000
- k=4, then after the operation x will become 0

To maximize the answer, you need to choose k=2 first, and then k=3, then the number will become 4000.

### Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

Each test case consists of positive integer x with a length of up to 2⋅105. It is guaranteed that there are no leading zeros in the integer.

It is guaranteed that the sum of the lengths of all integers x over all test cases does not exceed 2⋅105.

### Output
For each set of input data, output the maximum possible value of x after the operations. The number should not have leading zeros in its representation.

### Examples
```
Input
10
1
5
99
913
1980
20444
20445
60947
419860
40862016542130810467

Output
1
10
100
1000
2000
20444
21000
100000
420000
41000000000000000000
```

## Solution
For this, I first read in the number as a string (since it is too long to be stored in a long long) and then I convert it into a `vector<char>` (so it is mutable) and while doing this, I reverse it (so it's easier for my mind). Reversing it doesn't take time since I do it while converting into a `vector<char>`.

Then, I go through the number and see if the digit is greater than 5, if it is then you need to see how far this affects others. If the next one is a 9, then it doesn't just affect these two, it also affects the one after the nine.  
Then, if you reach the end (e.g. 99), add a one to the end of the number (e.g. 100). Otherwise, if you aren't at the end and it isn't a nine, then increment the digit by one.  

Then, I fill in the numbers from 0 up to the last one which got changed with zero because my code does it so 99 -> 199 and then you fill in the remaining two nines with zero. Thinking about it now though, it would be more efficient to change the numbers to zero as you go through the number.

Then print it out reversed (we reversed it at the start so re-reversing it puts it in the right order).  

[maximumrounding.cpp](./maximumrounding.cpp)

Solved! within competition