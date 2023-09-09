# Hidden Password
- [Problem](#problem)
- [Solution](#hidden.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/hidden)

### Description

Insecure Inc. has decided to shift directions after a failed attempt at developing a new encryption standard. Their new effort is a password system used to hide a password inside another string of characters we denote as a message. However, it is important that the message has a certain property relative to the hidden password.
Let us assume that we denote the characters of the password as ` c_1 c_2 ... c_ P` (although those characters need not be distinct). To be a valid message for the password, if you start from the beginning of the message and search for any character from the set `\{ c_1, ... , c_ P \} `, it must be that `c_1` is the first that you find. Subsequently, if you continue looking from that point of the message for any character from the set `\{ c_2, ... , c_ P \} `, it must be that `c_2` is the next that you find. Continuing in that manner, `c_3` must be the next character from the set `\{ c_3, ... , c_ P\} `, and so on until reaching `c_ P`.
For example, if the password is ABC, then the string HAPPYBIRTHDAYCACEY is a valid message. Notice that A is the first of the set `\{ `A, B, C`\} ` to appear in the message. (The initial H is not relevant.) Following the A that was found, the next occurrence from the set `\{ `B, C`\} ` is B. Following the B that was found, the next occurrence from the set `\{ `C`\} ` is indeed C. (Note that the A in DAY is not relevant, since we are only looking for a C at this point, and the additional A and C in CACEY are not relevant, because we have already completed the password with the first C.) However, for the password ABC, the string TRAGICBIRTHDAYCACEY is not a valid message. While the A is the first of the set `\{ `A, B, C`\} ` to appear in the string, the next occurrence from the set `\{ `B, C`\} ` is C rather than B. Also, the string HAPPYBIRTHDAY is not a valid message for the password ABC because the C never appears.
As an example with duplicate letters in the password, consider the password SECRET. For this password, the string SOMECHORESARETOUGH is a valid message. In contrast, the string SOMECHEERSARETOUGH is not a valid message, because an extraneous E is found at the point when an R is first expected.

### Input
The input consists of a single line containing two strings. The first string is the password, having length `P`, with `3 <= P <= 8`. The second string has length `S`, with `10 <= S <= 40`. Both strings will consist solely of uppercase letters. (That is, neither string can include whitespace, lowercase letters, digits, or other special characters.)

### Output
Output a single line with the word PASS if the second string is a valid message for the password, or FAIL otherwise. 

### Examples
```
Input

ABC HAPPYBIRTHDAYCACEY
Output

PASS
```
```
Input

ABC TRAGICBIRTHDAYCACEY
Output

FAIL
```
```
Input

ABC HAPPYBIRTHDAY
Output

FAIL
```
```
Input

SECRET SOMECHORESARETOUGH
Output

PASS
```
```
Input

SECRET SOMECHEERSARETOUGH
Output

FAIL
```


## Solution
Keep a map of every character and their occurrances.  
Keep a pointer to the start of P.  
Go through S,
- If the character is the next one in P, then move the pointer along one and decrease the occurrances of that character.
- Otherwise, see if it has any occurrances, if it does have an occurrance then something wrong has happened, so print FAIL

[hidden.cpp](./hidden.cpp)

Solved!