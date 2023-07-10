# all-just-a-dream
- [Problem](#problem)
- [Solution](#all-just-a-dream.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/dream?tab=metadata)

### Description
A common plot device in story-telling is the “All Just A Dream” trope. Typical symptoms of this trope being used are talking lions, main characters dying, yodeling aliens on monocycles, and a general plethora of weird events. Then, of course, someone wakes up and it is revealed that everything that happened during the entire season did in fact not happen at all. It was All Just A Dream (or some kind of hallucination), and the days of our lives spent watching all those episodes are lost forever. In order to cause further confusion and uncertainty, this can also be done in layers, with characters having dreams within dreams within dreams, and so on.

When the All Just A Dream trick is taken too far and gets used too often, it can get difficult to keep track of what has actually happened. This is where you enter the picture. You will be given a list of events, dreams, and scenarios. Each scenario specifies some events that have happened and some others that have not happened. Your job is to determine for each scenario whether that scenario is possible (possibly using the All Just A Dream trick).

### Input
The first line of input consists of an integer `0 <= n <= 50000`, the number of events, dreams and scenarios. Then follow `n` lines, giving the events, dreams, and scenarios in chronological order. Each line is in one of the following forms:
- An event line is of the form “E `e`”, indicating that event `e` happens (see below for format of `e`).
- A dream line is of the form “D `r`”, indicating that the last `r` events that happened were All Just A Dream. Note that these events are now considered to not have happened, so they should not be counted when processing subsequent D lines.
- A scenario line is of the form “S `k e_1 ... e_k`”, where `1 <= k <= 30` is an integer giving the number of events and `e_1, ..., e_k` is the list of events of the scenario. In a scenario, each event may be prefixed with a ‘!’, indicating that the event did not happen in this scenario.

Events are strings containing at most `20` characters and using only the characters ‘a’-‘z’ and underscores (‘_’). For ‘D’ lines, you can assume that `r` is an integer between `1` and `R`, where `R` is the total number of events that have happened so far (and that have not turned out to be a dream). For ‘E’ lines, you can assume that `e` is not an event that has already happened, except if the previous occurence of the event turned out to be a dream, in which case it can happen again

Warning

This problem has somewhat large amounts of input and output. We recommend you to make sure that your input and output are properly buffered in order to make the most of the few seconds of execution time that we give you.

### Output
For each scenario in the input, output a line as follows:
- “Yes” if the given scenario is consistent with what has happened so far.
- “`r` Just A Dream” if the given scenario would be consistent with what has happened so far, provided a “D `r`” line had occurred just before the scenario. If there are many possible values of `r`, choose the smallest value. Note that you should not consider this hypothetical “D `r`” line to have occurred (as illustrated by sample input 2 below).
- “Plot Error” otherwise.


### Examples
```
Input
10
E business_as_usual
E bobby_dies
S 1 bobby_died
E stuff_happens
E jr_does_bad_things
S 2 !bobby_dies business_as_usual
E it_goes_on_and_on
D 4
S 1 !bobby_dies
S 2 !bobby_dies it_goes_on_and_on
Output
Plot Error
3 Just A Dream
Yes
Plot Error
```
```
Input
11
S 1 !something
E one
E two
E three
E four
E five
S 3 three !four one
D 1
S 3 three !four one
D 1
S 3 three !four one
Output
Yes
2 Just A Dream
1 Just A Dream
Yes
```

## Solution
This is a difficult one.
Other than the two test cases they give you, you also have to consider the following case:
```
Input
9
E business_as_usual
E bobby_dies
S 1 bobby_died
E stuff_happens
E jr_does_bad_things
S 2 !bobby_dies business_as_usual
E it_goes_on_and_on
S 1 !bobby_dies
S 2 !bobby_dies it_goes_on_and_on
Output
Plot Error
3 Just A Dream
4 Just A Dream
Plot Error  -- this is because you can't delete it_goes_on_and_on to get to the bobby_dies
```

Have a map containing the event and the time the event occurred at.
Have a vector containing all the events chronologically.  

To add an event, add it to the vector and add it to the map with the current time. Then increment the time.  

To cover the dream deleting, using the vector you have of dream names, remove the right most string and remove it from the map as well. Then decrement time by an appropriate amount.

If it is a scenario, read through the events in the scenario.
For each event:
1. If it is prefixed by an `!`:
    a. Look at the map, if it is present within the map then we know there is a logical inconsistency with the dreams.
    b. So, to fix the inconsistency we need to delete a certain number of dreams. We need to delete the smallest number of dreams to fix every inconsistency.

2. Otherwise:
    a. Look at the map, if it isn't in the map then there is a plot hole.
    b. If it is in the map, we need to tell the program that you can't overwrite and reset this event or it will cause a plot hole. This covers the third input (the one I made)

Then, after parsing the events, print "Plot Error" if it is a plot error or if `normal >= lower` meaning you reset something that you needed to keep, so now it is inconsistent (this is sample input 3).
We can then easily see whether it is a dream or not by working out whether we actually changed the value from 1b. If we changed the value, it is a dream. Otherwise it isn't.

[all-just-a-dream.cpp](./all-just-a-dream.cpp)

Solved!