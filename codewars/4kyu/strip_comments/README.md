# Strip Comments

- [Problem](#Problem)
- [Solution](#Solution)

## Problem
[Problem Link](https://www.codewars.com/kata/51c8e37cee245da6b40000bd/train/python)

Complete the solution so that it strips all text that follows any of a set of comment markers passed in. Any whitespace at the end of the line should also be stripped out.

Example:

Given an input string of:  
```
apples, pears # and bananas
grapes
bananas !apples
```
The output expected would be:
```
apples, pears
grapes
bananas
```

The code would be called like so:

```py
result = solution("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"])
# result should == "apples, pears\ngrapes\nbananas"
```

## Solution
As soon as I saw this problem, I knew that regex would be the thing to use.  
To get the markers into the correct format so I can use them in regex, I joined them to an empty string. However, this caused problems. The '-' and '^' characters both have special importance inside a regex [], so I had to do \- and \^ instead, so I just joined to the empty string and used string.replace().  
The regex used was `\s*[{mark_string}].*`  

How to approach removing the comments from the string is where my solutions differ.  

### string.replace() on string.split(\n)
This was my first thoughts on doing it. This does pass the time requirement but I thought I could make it better.  
```
Split the string based on \n.
For each of these substrings, search in them for the regex term.
If the term is found, remove the length of the found term from the end of the substring.
Join all the substrings by \n.
```
[no_re_sub.py](solutions/no_re_sub.py)

### re.sub() on string.split(\n)
Looking to see how to improve my code made me remember about `re.sub()` because it is a function I should have used in past challenges but always forget about it.  
So, instead of removing the length of the found term from the substring, I just use `re.sub()` on the substring and join those sublists by \n.  
I'm not sure exactly how, but according to my random tests, this implementation is very slightly faster than no_re_sub.py and is the fastest of the three.
[re_sub_split.py](solutions/re_sub.py)

### re.sub() on the entire string
This then made me realise, why do it on substring when I can instead just do it on the entire string at once.  
This did require a change to my regex pattern because instead of looking for whitespace characters at the start, I had to do whitespace characters except the \n character and instead of just 'looping' to the end of the substring, I had to 'loop' until I found a \n character (indicating the comment has finished).
This has the least lines of the three files and in my opinion looks the nicest so it is the one I will submit, however it is slower than the other two by about 10%.  
[re_sub.py](solutions/re_sub.py)
