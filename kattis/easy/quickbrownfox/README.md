# Quick Brown Fox
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://open.kattis.com/problems/quickbrownfox)

### Description
 Photo by Neil McIntosh A pangram is a phrase that includes at least one occurrence of each of the `26` letters, ‘a’`... `‘z’. You’re probably familiar with this one: “The quick brown fox jumps over the lazy dog.”
Your job is to recognize pangrams. For phrases that don’t contain every letter, report what letters are missing. We’ll say that a particular letter occurs in the phrase if it occurs as either upper case or lower case.

### Input
Input starts with a line containing an integer `1 <= N <= 50`. The next `N` lines are each a single phrase, possibly containing upper and lower case letters, spaces, decimal digits and punctuation characters ‘.’, ‘,’, ‘?’, ‘!’, ‘’’ and ‘"’. Each phrase contains at least one and no more than 100 characters.

### Output
For each input phrase, output “pangram” if it qualifies as a pangram. Otherwise, output the word “missing” followed by a space and then the list of letters that didn’t occur in the phrase. The list of missing letters should be reported in lower case and should be sorted alphabetically. 

### Examples
```
Input

3
The quick brown fox jumps over the lazy dog.
ZYXW, vu TSR Ponm lkj ihgfd CBA.
.,?!'" 92384 abcde FGHIJ
Output

pangram
missing eq
missing klmnopqrstuvwxyz
```
```
Input

3
The quick brown fox jumps over the lazy dog.
ZYXW, vu TSR Ponm lkj ihgfd CBA.
.,?!'" 92384 abcde FGHIJ
Output

pangram
missing eq
missing klmnopqrstuvwxyz
```


## Solution

[quickbrownfox/src/main.rs](./quickbrownfox/src/main.rs)

Solved!