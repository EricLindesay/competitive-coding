# Tajna
- [Problem](#problem)
- [Solution](#tajna.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/tajna)

### Description

Every evening, little Ivica sends secret messages to little Marica through e-mail. Knowing Ivica’s e-letter travels unguarded through the network on its way to Marica’s e-mailbox, they have decided to encrypt every message using the following algorithm: Suppose Ivica’s message consists of `N` characters. Ivica must first find a matrix consisting of `R` rows and `C` columns such that `R <= C` and `R \cdot C = N`. If there is more than one such matrix, Ivica chooses the one with the most rows. Ivica writes his message into the matrix in row-major order. In other words, he writes the first segment of the message into the first row, the second segment into the second row and so on. The message he sends to Marica is the matrix read in column-major order. For instance, suppose Ivica wants to send the message “bombonisuuladici” containing 16 letters. He can use a `1 * 16`, `2 * 8`, or `4 * 4` matrix. Of these, the `4 * 4` has the most rows. When the message is written into it, the matrix looks like this, and the encrypted message becomes “boudonuimilcbsai”. b o m b o n i s u u l a d i c i Marica has grown tired of spending her precious time deciphering Ivica’s messages, so you must write a program to do it for her.

### Input
The input contains the received message, a string of lowercase letters of the English alphabet (with no spaces). The number of letters will be between 1 and 100.

### Output
Output the original (decrypted) message. 

### Examples
```
Input

bok
Output

bok
```
```
Input

koaski
Output

kakosi
```
```
Input

boudonuimilcbsai
Output

bombonisuuladici
```
```
Input

bok
Output

bok
```
```
Input

koaski
Output

kakosi
```
```
Input

boudonuimilcbsai
Output

bombonisuuladici
```


## Solution
To get the number of rows, take the floor of the square root and then decrement it until you get to a value which is divisible by the number.  
Decoding the message is easy and doesn't require any extra memory.

[tajna.cpp](./tajna.cpp)

Solved!