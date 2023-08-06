# Ads
- [Problem](#problem)
- [Solution](#ads.cpp)

## Problem
[Problem link](https://open.kattis.com/problems/ads)

### Description

Web pages are littered with ads (advertisements) these days. You wrote a simple program to detect images which are ads and remove them.
Characters that are any of the following are allowed in images: alphanumeric characters question mark ‘?’ exclamation mark ‘!’ comma ‘,’ full stop ‘.’ whitespace ‘ ’ Any images contained characters that are not allowed are considered ads, and will be removed by your program. The ‘`+`’ character will be used only as the border of an image.
All images will follow these rules: They are all axis-aligned rectangles with ‘`+`’ as its border and is at least `3 x 3` big (including the borders). All ‘`+`’ characters belong to the border of exactly 1 image. Borders of different images will not be adjacent to each other (contact at their corners is also not allowed). They can contain other images while adhering to the rules above. For every banned character that is found inside at least one image, in order not to remove too many unnecessary parts of the images on the web page, you decide that the smallest image (in terms of pixel count) that contains that character will be flagged as an ad and removed. When an ad is removed, every character inside the ad and the border is replaced with a whitespace. Note that the web page is not considered an image. Characters found on the web page that is not in any image should not be removed.

### Input
The first line of the input contains `1 <= H <= 200` and `1 <= W <= 200`, the height and width of the web page to be processed respectively. `H` lines follow, each line contain exactly `W` ASCII characters whose ASCII decimal value fall in the range `[32, 126]`.

### Output
Output the web page with all the ads removed. Do not print extra spaces or new lines.
Subtasks (21 Points): There is no ads in the web page at all. (21 Points): There is either one image or no image in the web page. (28 Points): No images will be found inside other images. (30 Points): No additional constraint. 

### Examples
```
Input
8 20
 apples are great!  
++++++++++++++++++++
+ oranges are      +
+ way better!      +
+ #oranges>apples  +
++++++++++++++++++++
 check out our      
 fresh apples!      

Output
 apples are great!  
                    
                    
                    
                    
                    
 check out our      
 fresh apples!      
```
```
Input
7 7
+++++++
+  =  +
+ +++ +
+ + + +
+ +++ +
+     +
+++++++

Output
       
       
       
       
       
       
       
```
```
Input
7 7
+++++++
+     +
+ +++ +
+ +=+ +
+ +++ +
+     +
+++++++

Output
+++++++
+     +
+     +
+     +
+     +
+     +
+++++++
```
```
Input
11 11
+++++++++++
+         +
+ +++++++ +
+ +     + +
+ + +++ + +
+ + + + + +
+ +=+++ + +
+ +     + +
+ +++++++ +
+         +
+++++++++++

Output
+++++++++++
+         +
+         +
+         +
+         +
+         +
+         +
+         +
+         +
+         +
+++++++++++
```

## Solution

### Initial Approach
Initial approach when talking with Dom is first find a bad character, a bad character MUST be in an ad. Then, you can go up and left to find where the ad starts and, from there, find the bottom right of the ad. Then loop through and fill those with whitespace.  

This seems to work however gave `Time Limit Exceeded`.

[ads.cpp](./ads.cpp)

### Recursive Approach
When you find a `+`, this must be the start of an ad, so call a function, saying you've found an ad at this position.  

Within that function, loop through and first find the right most position of the ad.  
Then, loop through the ad. If you are at the bottom then stop, if you see another `+` then there is another ad inside this ad, so call the function recursively on that, if you see an invalid character then set a flag and stop looping.  

If the flag is set, then fill the grid with whitespace for the ad you are currently in.  

Then set the x and y position passed into the function (as a reference) to the bottom right of the ad so you don't loop over something you have already checked.

This is much faster, however, it gives a `Wrong Answer!`.

Turns out, you can't increment x and y at the end to make sure you don't loop twice because it can cause bugs. However, with that being removed you can move the print for the output into the while loop, removing the need to print at the end separately.
This still gave wrong answer.

The fix to it was to find the bottom value outside, like when you find the right value. I'm not sure why my logic for stopping if its the bottom didn't work but it works now.

[recursion.cpp](./recursion.cpp)

Solved!