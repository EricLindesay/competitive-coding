# How Many Are Smaller Tham Me II

- [Problem](#Problem)
- [Solution](#Solution)

## Problem

[Problem Link](https://www.codewars.com/kata/56a1c63f3bc6827e13000006/train/python)

This is a hard version of [How many are smaller than me?](https://www.codewars.com/kata/56a1c074f87bc2201200002e). If you have troubles solving this one, have a look at the easier kata first.

Write `function smaller(arr)` that given an array arr, you have to return the amount of numbers that are smaller than arr[i] to the right.  

For example:
- smaller([5, 4, 3, 2, 1]) === [4, 3, 2, 1, 0]
- smaller([1, 2, 0]) === [1, 1, 0]

## Solution

### Brute Force
Of course try brute forcing it with a nested for loop. O(n^2) complexity.  
The purpose of this is to make sure I understand what the problem wants.
[brute_force.py](solutions/brute_force.py)  

### Using a Sorted Sublist
This is essentially the same as doing brute force but before you start looping over the right sublist, you sort it first. This allows you to break as soon as you find a value greater than the current.  
This is slower than using brute force because you have to do the sorting. I was hoping the inbuilt sort would be efficient enough to save time but that is not the case.
[sorted_sublist.py](solutions/sorted_sublist.py)

### Using a Dictionary  
If you loop through the list backwards, you can add to a dictionary containing the counts of what you have seen.  
This means you only need to loop through the list once and then loop through the dictionary for each loop.  
This is still O(n^2) but should be more efficient when you have lots of duplicates because they get 'mapped' to the same position.   
However, when tested against the brute force solution, the brute force is much faster. This confuses me but oh well.    
[dictionary.py](solutions/dictionary.py)

Example showing how the values in the dictionary change.
```py
input = [5,3,9,2,2]
dict = {2:1}
dict = {2:2}
dict = {2:2, 9:1}
dict = {2:2, 9:1, 3:1}
dict = {2:2, 9:1, 3:1, 5:1}
```

### Using an Ordered Dictionary
One of the major issues with using the dictionary how I did before is that the entire dictionary must be looped through each time.  
If the dictionary keys are ordered, you can just go until you find a key greater than the current value and stop.  
This means you don't need to loop through the entire dictionary each time.  
The major issue with this is that python dictionaries are not ordered by default.  
collections.OrderedDict can be used in this scenario. This is not an easy task to implement though. OrderedDict does not have a method for insertion, only appending and prepending.  
My solution to try and fix this is currently not working as OrderedDict doesn't like being manipulated using for loops so I'll have to find a way around that.  
[ordered_dict_no_deletes.py](solutions/ordered_dict_no_deletes.py)

Example of how I want OrderedDict to work
```py
input = [5,3,9,2,2]
dict = {2:1}
dict = {2:2}
dict = {2:2, 9:1}
dict = {2:2, 3:1, 9:1}
dict = {2:2, 3:1, 5:1, 9:1}
```
