# Majority Card
- [Problem](#problem)
- [Solution](#majoritycard.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/majoritycard)

### Description

You are going to play a Majority1 Card game. In this game, there will be a deck of cards, initially empty. Each card is labelled with a number between `1` to `2~ 000~ 000~ 000` (or just between `1` to `20` on some occasions.) You will play the game in `N` rounds, consecutively. For each round, one of these four possible scenarios can happen: “PUT_TOP `X` `Y`”: You put `X` many cards labelled `Y` at the top of the deck. “PUT_BOTTOM `X` `Y`”: You put `X` many cards labelled `Y` at the bottom of the deck. “REMOVE_TOP `Z`”: You remove the `Z` top-most cards. “REMOVE_BOTTOM `Z`”: You remove the `Z` bottom-most cards. After each round, you have to answer this question: “What is the majority card in the deck?” A majority card is a card label that appears the most in the deck and if tied, pick the smallest one. Can you help yourself by writing a program to play the Majority Card?

### Input
The first line contains an integer, `N (1 <= N <= 200~ 000)`. The next `N` lines contain the rounds, each on one line. Each round is given in one of four forms mentioned in above description where: `1 <= X <= 10~ 000`, `1 <= Y <= 2~ 000~ 000~ 000`, and `1 <= Z <= C-1` where `C` is the number of cards in the current deck (i.e. there will still be at least one card in the deck after each removal scenarios.) 

### Output
For each round, print the smallest majority card, separated by a newline.
Subtasks (`18` Points): `N <= 2~ 000`, `X = 1`, `Y <= 20`. (`15` Points): `X = 1`, `Y <= 20`. (`29` Points): `Y <= 20`. (`6` Points): The rounds are only PUT_TOP and PUT_BOTTOM. (`20` Points): The rounds are only PUT_TOP and REMOVE_TOP. (`12` Points): No additional constraint. Warning
The I/O files are large. Please use fast I/O methods.
Explanation of Sample 1 After the `1`-st round, the smallest majority card is `20`. After the `2`-nd round, the smallest majority card is `17` (tied with `20`.) After the `3`-rd round, the smallest majority card is `8` (tied with `17` and `20`.) After the `4`-th round, the smallest majority card is `17`. After the `5`-th round, the smallest majority card is `17` (tied with `20`.) After the `6`-th round, the smallest majority card is `20`. After the `7`-th round, the smallest majority card is `17` (tied with `20`.) Explanation of Sample 2 After the `1`-st round, the smallest majority card is `2`. After the `2`-nd round, the smallest majority card is `7`. After the `3`-rd round, the smallest majority card is `7`. After the `4`-th round, the smallest majority card is `13`. After the `5`-th round, the smallest majority card is `7` (tied with `13`.) After the `6`-th round, the smallest majority card is `2` (tied with `13`.) After the `7`-th round, the smallest majority card is `13`. 

### Examples
```
Input
7
PUT_TOP 1 20
PUT_TOP 1 17
PUT_TOP 1 8
PUT_BOTTOM 1 17
PUT_BOTTOM 1 20
REMOVE_TOP 2
REMOVE_BOTTOM 1
Output
20
17
8
17
17
20
17
```
```
Input
7
PUT_TOP 2 2
PUT_BOTTOM 4 7
PUT_TOP 3 13
PUT_BOTTOM 2 13
REMOVE_TOP 1
REMOVE_BOTTOM 5
REMOVE_BOTTOM 2
Output
2
7
7
13
7
2
13
```
12
PUT_TOP 2 2
PUT_TOP 5 2
PUT_TOP 9 2
PUT_TOP 2 3
PUT_TOP 3 4
PUT_TOP 3 3
PUT_BOTTOM 4 7
PUT_TOP 3 13
PUT_BOTTOM 2 13
REMOVE_TOP 1
REMOVE_BOTTOM 5
REMOVE_BOTTOM 2

## Solution
Have a list (for quick putting on top and bottom) of cards.  
Have a map of card to frequency of the card in the list.  

When putting into the list, use `list.insert` to do multiple at once.  
When removing from the list, you have to remove one by one from the list, so that you can update the map.  

Then the difficulty is finding the most frequent one. The best thing to do would be to use a priority queue with frequency, but then the difficulty is finding the item in the PQ. My thought is maybe have a PQ of pointers and then you also access that pointer with the map. But when you change the pointer, the PQ doesn't update which is the problem.  

An obvious efficiency improvement to this is to remove multiple adjacent cards at once if they exist.  

[majoritycard.cpp](./majoritycard.cpp)