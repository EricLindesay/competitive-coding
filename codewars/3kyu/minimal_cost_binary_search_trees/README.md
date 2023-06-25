# Minimal Cost Binary Search Trees
Incomplete
- [Problem](#Problem)
- [Solution](#Solution)

## Problem
[Problem Link](https://www.codewars.com/kata/571a7c0cf24bdf99a8000df5/train/python)

The description that follows presumes that you have completed [Binary Search Trees](https://www.codewars.com/kata/binary-search-trees). Before starting on this kata, fill in the code for Tree's `__eq__`, `__ne__`, and `__str__` methods as described and verified by that kata.

Imagine you have a binary search tree and after some time you notice that some of the nodes are accessed more frequently than others. The time it takes to access a node depends on how deep the node is in the tree, so ideally you would want nodes that are accessed often placed close to the root. The purpose of the this kata is to "balance" the tree such that the average cost of accessing nodes is minimized.

Each node has a `weight` attribute which could represent how often the node is accessed. For each node in a tree, one can associate a cost, which is the weight of the node times its depth. The depth of the root node is defined to be 1, and the depth of a node directly below a node of depth `d` is `d + 1`. The cost of a tree is simply the sum of the costs of its nodes. Your first task is to write a function cost that takes a tree as argument and returns the cost of the tree.

Now we are getting to the more challenging part of this kata. Your final task is to write a function `make_min_tree` that takes a non-empty list of nodes as argument and returns a tree with minimal cost. The list passed as argument is sorted in ascending order. No two nodes in the list are equal (under the definition of "equal" provided by `__eq__` and `__ne__`). For this last part, your code will be tested with lists up to a length of 100. (Note: My algorithm is quadratic in space and cubic in time, but I am not sure it cannot be done better.)


## Solution
Finding the cost was easy, its just a recursive function.  

### Notes
So when you pick the root nodes, take the left sublist and the right sublist for all the scenarios and find the best trees for those.

### Brute Force
Find every possible tree.  
Go through the list and get the two sublists to the left and right of this. Call the function recursively on those sublists.  
This is too slow.  
[brute_force.py](solutions/brute_force.py)  

### Best Three
Through testing, I confirmed (see [functools.cache](#functools.cache) section) that the root node of the best tree is always in the top three weights for the list of nodes.  
This allows us to reduce the search space. Now, instead of finding the left and right subtrees for all nodes, we can just focus on the top three.  
This was better but still too slow.  
[best_three.py](solutions/best_three.py)

### functools.cache
After best_three was too slow, I remembered about the functools.cache decorator.  
This caches the result of recursion, making it much faster.  
This will be especially good for this since we are likely to do something multiple times through a different path.  
For this to work, I had to implement `__hash__` in Node and had to pass the array through as a tuple.  
This was fast enough to run all of the tests however not all of the tests gave the correct answer.  
The issue is that the root node (found using brute force) is not in the top three.  
So now I need another way of reducing the search space.  
[hashable.py](solutions/hashable.py)



