# Checking For Correctness
- [Problem](#problem)
- [Solution](#checkingforcorrectness.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/checkingforcorrectness)

### Description

In mathematics, it’s always important to check your work. Usually, this means making some sort of quick calculation (either in your head, or on paper) to ensure that the answers you find make sense.
Your colleague has written an implementation of a general arithmetic system which supports arbitrarily large numbers and operations like addition, multiplication, exponentiation. She has asked you to write an independent program that checks that the answers her software gives make sense (though they may not be perfectly correct!).
Write a program that checks the correctness of simple arithmetic statements of the form: a + b a * b a ^ b That is, addition, multiplication, and exponentiation. The output of your program is the value of the smallest-order `4` digits of the answer. Then your colleague can check whether her software gave the same digits for that portion. If not, you know there’s a problem!

### Input
Input consists of a sequence of up to `30, 000` arithmetic expressions, one per line, in the format given above. All tokens are separated by single spaces. All numbers are integers in the range `[0, 2^{32})`. Input ends at the end of file.

### Output
For each expression, print the last `4` digits of the answer, omitting any leading zeros. 

### Examples
```
Input

4231 + 13402
4231 * 13402
4231 ^ 13402
4321 ^ 7
Output

7633
3862
3361
641
```


## Solution

Addition and multiplication is easy. Just take the last four digits and add/multiply them and then return the last four digits of the answer.  
Exponentiation is much more difficult.  
You should be able to block the first number so that it only uses the last four digits of this number (because it works the same as mulitplication). But I don't think you can just get the last four digits of the second number because it will give the wrong result. But doing the entire exponentiation takes too long.  
You may have to look for cycles in the exponentiation. There may be a time where it loops back on itself and comes to the same four end digits again.
E.g. with powers of 2.
```
2^6

2*2 = 4, 4 % 10 = 4
4*2 = 8, 8 % 10 = 8
8*2 = 16, 16 % 10 = 6
6*2 = 12, 12 % 10 = 2  -- we have found the start of a loop, since we have already seen the value `2` at the start
So, now we can use the loop to see that we have already done 4 loops and need to do 2 more.
Which we can look up and see it is 8, without any extra calculations.
```

But you have to be careful, the loop doesn't always start/end at one value.

I've implemented that, and it works for the large sample input, now I just need to try submit it later.

That gives a wrong answer.
You also can't just manually do the exponentiation by multiplying since it causes a Time limit exceeded error.

[checkingforcorrectness.cpp](./checkingforcorrectness.cpp)