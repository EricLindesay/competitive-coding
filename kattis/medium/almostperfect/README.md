# Almost Perfect
- [Problem](#problem)
- [Solution](#almostperfect.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/almostperfect)

### Description

A positive integer `p`is called a perfect number if all theproper divisors of `p` sumto `p` exactly. Integer`d` is a proper divisor of`p` if `1 <= d <= p-1` and `p` is evenly divisible by`d`. For example, thenumber `28` is a perfectnumber, since its proper divisors (which are `1`, `2`, `4`, `7` and `14`) add up to `28`.

Perfect numbers are rare; only `50` of them are known (as of 2017).Perhaps the definition of perfection is a little too strict.Instead, we will consider numbers that we’ll call almost perfect. Positive integer `p` is almost perfect if the properdivisors of `p` sum to avalue that differs from `p` by no more than two.

### Input
Input consists of a sequence of up to `500` integers, one per line. Eachinteger is in the range `2` to `10^9` (inclusive). Input ends at endof file.

### Output
For each input value, output the same value and then one ofthe following: “perfect” (if the number is perfect), “almostperfect” (if it is almost perfect but not perfect), or “notperfect” (otherwise).

### Examples
```
Input
6
65
650
Output
6 perfect
65 not perfect
650 almost perfect
```


## Solution
Do a for loop up to the square root of the number.
See if `i` is divisible, if it is then also see if `num/i` is divisible.  
For the ones which are divisible, add it to the `divisorSum`.  
Then use this number to compare with the input number to detemine whether it is perfect/almost/not.

[almostperfect.cpp](./almostperfect.cpp)

Solved!
