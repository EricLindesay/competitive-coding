# The Stock Market
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/borsen)

### Description

Evelina is going to start speculating on the stock market to become rich. She is actually not really interested in economics and never bothers to read more than the first stock price in the newspaper. But, she thinks, it’s everyone else who is complicating things. If you buy and sell a stock at the right time you could just as well earn money on this one company, which we call `A`. By always asking her friends about the amount of fish balls they eat she has learned to exactly predict the price of `A` for the next `N` days. Write a program that computes the amount of money she has at the end of that period if she starts with `100` SEK and invests optimally. She can never borrow money, she must use her own.
The stock price is updated daily and is the same for both buying and selling stocks. Each day Evelina can either buy any amount of stock, sell any amount of stock or do nothing. The amount she purchases doesn’t have to be an integer. For each transaction, she must pay a fixed fee as a commission. The fee is paid in cash, that is before she buys stocks she must pay a fee, and after she sells stocks she must pay a fee.

### Input
The first line contains the integer `N` (`2 <= N <= 100, 000`), the number or days.
The second line contains a decimal number `Q` (`0 <= Q <= 100`), the fee in SEK per transaction.
This is followed by `N` lines each containing a decimal number, the stock price for each day. The price is always between `1` and `1, 000` SEK.
All decimal numbers have at most `10` digits after the decimal point.

### Output
Output the maximum amount of money she can have after `N` days. Your answer will be considered correct if it has a relative or absolute error of at most `10^{-5}`.
Scoring
Your solution will be tested on a set of test case groups. To get the points for a group, you need to pass all the test cases in the group. Group Points Constraints `1` `30` `N <= 14` `2` `40` `N <= 1, 000` `3` `30` No further constraints. 

### Examples
```
Input
6
2.3
75.6
86.2
83.1
91.3
72.5
95.7
Output
147.3742063492
```
```
Input
6
2.3
75.6
86.2
83.1
91.3
72.5
95.7
Output
147.3742063492
```


## Solution

[borsen.cpp](./borsen.cpp)