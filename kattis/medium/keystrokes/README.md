# Keystrokes
- [Problem](#problem)
- [Solution](#Keystrokes.cpp)

5.4 - Medium

## Problem
[Problem link](https://open.kattis.com/problems/lyklagangriti)

### Description
Benni was browsing the web and accidentally picked up a keylogger. Fortunately, Benni’s computer has virus protection which alerted him, but the protection did not remove the virus. When Benni types a password on a web page, he tries to hide it so that the keylogger does not get his password. In order to obscure his password, he enters it in a strange way. He uses the left and right arrow keys to move the cursor, and erases characters with backspace. If you are given the sequence of keystrokes that Benni used to enter his password, can you figure out what his password is?

### Input
The input is one line containing a string of length `n`. Benni only writes lowercase letters and digits, but when he presses the left arrow key, the right arrow key, or the backspace key, they are indicated by L, R, or B, respectively. Neither B nor L appear in the string if the cursor is in front of the first letter and R does not appear if the cursor is after the last letter.

### Output
Print one line containing only Benni’s password.

### Examples
```
Input
iLnLnLeLb
Output
benni
```
```
Input
arnarLLLBBun
Output
unnar
```
```
Input
password123
Output
password123
```

## Solution
This is pretty simple. Store the output characters as a doubly linked list. Then store the cursor position as an iterator to the elements in the list.  
If you read a 'L', decrement the cursor, 'R', increment the cursor and 'B', delete the element.  
I chose a linked list for this because linked lists have good insertion and deletion and this problem will have a lot of insertion as well as some deletion.  

[keystrokes.cpp](./keystrokes.cpp)

Solved!