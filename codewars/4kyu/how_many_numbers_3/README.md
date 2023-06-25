# How Many Numbers III 

- [Problem](#Problem)  
- [Solution](#Solution)  

## Problem
____________________________________________

[Problem Link](https://www.codewars.com/kata/5877e7d568909e5ff90017e6/train/python)

We want to generate all the numbers of three digits where:
- the sum of their digits is equal to 10.
- their digits are in increasing order (the numbers may have two or more equal contiguous digits)

The numbers that fulfill the two above constraints are:   
```[118, 127, 136, 145, 226, 235, 244, 334]```


Make a function that receives two arguments:
- the sum of digits value
- the desired number of digits for the numbers  


The function should output an array with three values: [1,2,3]  
1. The total number of possible numbers
2. The minimum number
3. The maximum number

```py
# The example given above should be:
find_all(10, 3) == [8, 118, 334]
```

```py
# If we have only one possible number as a solution, it should output a result like the one below:
find_all(27, 3) == [1, 999, 999]
```

```py
# If there are no possible numbers, the function should output the empty array.
find_all(84, 4) == []
```

```py
# The number of solutions climbs up when the number of digits increases.
find_all(35, 6) == [123, 116999, 566666]
```

Features of the random tests:
- Number of tests: 112
- Sum of digits value between 20 and 65
- Amount of digits between 2 and 17

_______________

## Solution

### Initial Thoughts
My initial thought was to just loop through every value and brute-force the solution.   
I knew this would likely not be efficient enough but a bad solution is better than no solution.  
[brute_force.py](solutions/brute_force.py)

### Bound Optimisation
Seeing that the brute force solution was too slow, I knew a simple way to improve the solution is to reduce the search space.  
We can immediately discount values which are impossible to reach, these being when `sum_dig > 9*digs` and when `sum_dig < digs`.  
Since we know that the number's digits are ascending, the smallest value is 11111 instead of 10000.  
Additionally, the upper bound is limited to sum_dig/digs repeated, which I primarily discovered through trialling a lot of different values to see if I could spot any patterns between them.  
[bound_optimisation.py](solutions/bound_optimisation.py)  

#### After this, I then found that you can actually directly calculate the lower and upper bounds.  
The lower bound you can calculate through the following steps:  
- sum_dig - digs = diff  
- diff / 8 = the number of trailing 9s  
- diff % 8 + 1 = the remainder of the sum_dig-current_upper_bound. Add this to the beginning of the string.
- Add any leading 1s.

Example of Lower Bound
```py
find_all(20,3)
crude_lower = 111  # start out with all ones
20 - sum(111) = 17
17 // 8 = 2
lower = 199  # you can safely set the 2 latest numbers to 9

20 - sum(199) = 1
lower = (1+1)99
lower = 299  # update the leading numbers to add up to the goal sum
```  

The upper bound, can be calculated in a very similar way.  
Instead of adding onto the right most value, you take away by one, starting with the left most value and moving towards the end.  

Example of Upper Bound
```py
find_all(19,3)
ceil(19/3) = 7
crude_upper = 777  # start out with all 7s
sum(777) - 19 = 2  # there is a difference of two with the goal sum, so remove those two

upper = (7-1)(7-1)7  # remove the two
upper = 667
```
[bound_optimisation2.py](solutions/bound_optimisation2.py)

#### Checking which is better
Although I highly suspected that bound_optimisation2 is better than bound_optimisation, I created a function to test the two programs against each other with random input.  
This test resulted in optimisation2 taking about half as much time as optimisation1.  

### Using an Iter
A large inefficiency with using range() is that it goes through values we know will be invalid.  
For example, if we have `120`, we know that `121` is also invalid, so we should instead just skip to `122`.  
This is what the ascending_numbers() function does.  
If it sees that the numbers are no longer ascending, it would skip over `121` and go straight so something which is valid and is ascending.     
[iter.py](solutions/iter.py)

