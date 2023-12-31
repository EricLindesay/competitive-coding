# card-trick2
- [Problem](#problem)
- [Solution](#card-trick2.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/cardtrick2)

### Description
The magician shuffles a small pack of cards, holds it face down and performs the following procedure:
- The top card is moved to the bottom of the pack. The new top card is dealt face up onto the table. It is the Ace of Spades.
- Two cards are moved one at a time from the top to the bottom. The next card is dealt face up onto the table. It is the Two of Spades.
- Three cards are moved one at a time . . .
- This goes on until the `n`th and last card turns out to be the `n` of Spades.

This impressive trick works if the magician knows how to arrange the cards beforehand (and knows how to give a false shuffle). Your program has to determine the initial order of the cards for a given number of cards.

### Input
On the first line of the input is a single positive integer `T <= 13` the number of test cases to follow. Each case consists of one line containing the integer `n (1 <= n <= 13)`.

### Output
For each test case, output a line with the correct permutation of the values `1` to `n`, space separated. The first number showing the top card of the pack, etc…

### Examples
```
Input
2
4
5
Output
2 1 4 3
3 1 4 5 2
```

## Solution

Think of it as a linked list. Then loop around this linked list doing the increments, if you see one you've already seen, skip it.

[card-trick2.cpp](./card-trick2.cpp)

Solved!