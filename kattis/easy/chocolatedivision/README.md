# Chocolate Division
- [Problem](#problem)
- [Solution](#chocolatedivision.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/chocolatedivision)

### Description

Alf and Beata were two young adults living together a long,
long time ago, before you could spend all your afternoons
competing in programming. Their lives were thus much more
boring than those of today’s young adults. How could you even
survive back then, you might ask yourself. The answer is
simple: you make your own chocolate bars! Our two cohabitants
loved making chocolate bars, and often had huge piles of them
each afternoon. To avoid filling their entire living room with
chocolate bars, Beata challenged her friend to a game every
evening to eat up all the chocolate – the Chocolate Division
game.

The Chocolate Division game is played by two players (in our
case, Alf and Beata) using a chocolate bar consisting of
`R` rows, each containing `C` squares of chocolate.

A move consists of splitting a rectangular piece of chocolate
either horizontally or vertically into two pieces, such that
the two new pieces again have integer height and width. The
first move is performed on the original chocolate bar. Each
subsequent move can performed on any piece of chocolate that
has been split off so far, as long as it doesn’t have
dimensions `1 * 1` (no split can be done on such a piece). Alf starts with the first move. If, at any point, a person can not perform their move because all remaining pieces have size `1 * 1` squares, that person loses.

Can you compute who wins the game, if both players play
optimally?

### Input
The first and only line contains the integers `R` and `C` (`1
<= R, C <= 500`), the height and width of the original
chocolate bar.

### Output
Output Alf if Alf wins the game,
or Beata if Beata wins the game.


### Examples
```
Input
1 1
Output
Beata
```
```
Input
1 2
Output
Alf
```
```
Input
2 2
Output
Alf
```


## Solution

[chocolatedivision.cpp](./chocolatedivision.cpp)