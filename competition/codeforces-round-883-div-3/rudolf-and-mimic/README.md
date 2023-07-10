# rudolf-and-mimic
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://codeforces.com/contest/1846/problem/F)

### Description
This is an interactive task.

Rudolph is a scientist who studies alien life forms. There is a room in front of Rudolph with `n` different objects scattered around. Among the objects there is exactly one amazing creature — a mimic that can turn into any object. He has already disguised himself in this room and Rudolph needs to find him by experiment.

The experiment takes place in several stages. At each stage, the following happens:
- Rudolf looks at all the objects in the room and writes down their types. The type of each object is indicated by a number; there can be several objects of the same type.
- After inspecting, Rudolph can point to an object that he thinks is a mimic. After that, the experiment ends. Rudolph only has one try, so if he is unsure of the mimic's position, he does the next step instead.
- Rudolf can remove any number of objects from the room (possibly zero). Then Rudolf leaves the room and at this time all objects, including the mimic, are mixed with each other, their order is changed, and the mimic can transform into any other object (even one that is not in the room).
- After this, Rudolf returns to the room and repeats the stage. The mimic may not change appearance, but it can not remain a same object for more than two stages in a row.

Rudolf's task is to detect mimic in no more than five stages.

### Input
The first line contains one integer `t (1 ≤ t ≤ 1000)` — the number of test cases.

The first line of each test case contains one integer `n (2 ≤ n ≤ 200)` — the number of objects in the room.

The second line of each test case contains `n` integers `a1,a2,...,an (1 ≤ ai ≤ 9)` — object types.

### Interaction

After you have read the description of the input data set, you must make no more than `5` queries. Reading the input data is considered the beginning of the first stage, and the mimic may already begin to change.

The request is a line. The first character of the line indicates the request type. To remove objects, print "-". After that print the number `k` — how many objects you want to remove. Then there are `k` numbers — indexes of objects in their current location. Indexing starts from one. You can remove the mimic, but in this case you will not be able to point to it and will get "Wrong answer" verdict.

In response to the request you will receive a line containing integers — the objects remaining in the room after removal and mixing.

To indicate the position of a mimic, print "!", then print the index of the object that is the mimic.

The task will be considered solved if the position of the mimic is specified correctly.

If you make more than five requests, or make an invalid request, the solution will get "Wrong answer" verdict.

After outputting a query or the answer do not forget to output the end of line and flush the output. Otherwise, you will get "Idleness limit exceeded". To do this, use:

- fflush(stdout) or cout.flush() in C++;
- System.out.flush() in Java;
- flush(output) in Pascal;
- stdout.flush() in Python;
- see documentation for other languages. 

### Hacks
You can hack a solution with the following input format.

The first line contains one integer `t (1 ≤ t ≤ 1000)` — the number of test cases.

The first line of each test case contains two integers `n, k (2 ≤ n ≤ 200, 1 ≤ k ≤ n)` — the number of objects and the position of the mimic.

The second line contains of each test case `n` integers `a1, a2,...,an (1 ≤ ai ≤ 9)` – initial array of objects.

### Examples
```
Input
3
5
1 1 2 2 3

2 1 1 2

2 2 2

2

8
1 2 3 4 3 4 2 1

4 3 4 3 2 2 1 3
 
2 3 3 2

5 3 2

2 5

15
1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 

1 2 3 4 5 6 7 8 7 9 5 4 3 2 1 
Output
- 1 5

- 1 3

- 2 1 2

! 1


- 0

- 4 1 3 7 8

- 1 4

- 1 2

! 2


- 0

! 10
```

### Note
Explanation for the first test: initial array is x1, x2, x3, x4, x5. Mimic is in first position.
- Delete the fifth object. After that, the positions are shuffled, and the mimic chose not to change his appearance. Object positions become x4, x1, x2, x3. 
- Delete the third objects. The mimic is forced to turn into another object, because it has already been in the form 1 for two stages. The mimic chose to transform into 2, the objects are shuffled and become x3, x4, x1.
- Delete the first and second objects. The objects positions become x1. Only the mimic remains, and it remains an object 2.
- Point to the first element.


## Solution

I didn't really know what to do for this one. This was a bit difficult since the example is quite unclear on the exact limitations on the mimic's movement. I.e. can the mimic start off as one that isn't already there? Can it start as 3 in the first example? If it can, then why do they remove 3? I think it might be a red herring.

I didn't have time to do this within the competition but my idea was to:
- Get the list of numbers
- Get the list of numbers again without removal
- if nothing changed, get the list again (in this case it must change).

Then you can compare the numbers which changed during that mix up and then you can narrow it down very quickly to which number the mimic is within. Then you can remove all of the other ones.
Then you can do the same thing as before, wait until the mimic changes (the mimic guarantees to change within 2 mixes) and then find the odd one out. This means you'll find the mimic in 4 swaps at worst.

[rudolf-and-mimic.cpp](./rudolf-and-mimic.cpp)