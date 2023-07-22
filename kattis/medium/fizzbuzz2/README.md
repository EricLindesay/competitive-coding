# FizzBuzz
- [Problem](#problem)
- [Solution](#fizzbuzz2.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/fizzbuzz2)

### Description

A company is hiring a software engineer to a top secret job.   After a lot of headhunting they now have `N` candidates left, denoted   `1` to `N` after anonymization. To test the   skills of the candidates, the company has asked them to   implement FizzBuzz.
A correct implementation of FizzBuzz does the following. For   each of the integers `1`   to `M`,
if the number is divisible by `3`, output “fizz”,
if the number is divisible by `5`, output “buzz”,
if the number is divisible by both `3` and `5`, output “fizzbuzz”, and
if the number is divisible by neither `3` and `5`, output the number itself.
Since the job is top secret, the company cares very much   about the right thing being printed in the right place. Your   task is to find the candidate whose program outputs the right   thing at the right place the most times.

### Input
The first line of the input consists of the integers   `N` (`2 <= N <= 1000`) and `M` (`2   <= M <= 100`), the number of candidates and the   number of values their programs should output.
The next `N` lines each   contain `M` strings   consisting only of small letters a-z   and digits `0`-`9`,   separated by a single whitespace. The `i`’th of these lines contains the   output from candidate `i`.   Each of the `M` strings in   the output from a candidate contains at least one   character.

### Output
Print the number of the candidate whose output has the most   correct things printed in the correct place. In case of a tie,   output the candidate with the lowest number.

### Explanation of example 1
In the example, the third candidate output the right thing   at every place. The other two have at least one incorrect   output, so the third candidate has the most correct words.

### Examples
```
Input
3 15
1 2 fizz 4 5 fizz 7 8 fizz 10 11 fizz 13 14 fizz
1 2 3 4 buzz 6 7 8 9 buzz 11 12 13 14 buzz
1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz
Output
3
```
```
Input
3 6
fizz fizz fizz fizz buzz fizz
2 fizz 4 buzz fizz 7
1 2 3 4 5 6
Output
1
```
```
Input
2 6
01 is fizz lizzy of norway
nr 2 is really buzz lightyear
Output
2
```


## Solution
Keep track of the best candidate and the score they got.

[fizzbuzz2.cpp](./fizzbuzz2.cpp)

Solved!