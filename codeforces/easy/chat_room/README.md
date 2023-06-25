# Chat room - 1000
**Tags**: Greedy, Strings  
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem Link](https://codeforces.com/problemset/problem/58/A)  

Vasya has recently learned to type and log on to the Internet. He immediately entered a chat room and decided to say hello to everybody. Vasya typed the word `*s*`. It is considered that Vasya managed to say hello if several letters can be deleted from the typed word so that it resulted in the word "`hello`". For example, if Vasya types the word "`ahhellllloou`", it will be considered that he said hello, and if he types "`hlelo`", it will be considered that Vasya got misunderstood and he didn't manage to say hello. Determine whether Vasya managed to say hello by the given word `*s*`.  
  
### Input
The first and only line contains the word `*s*`, which Vasya typed. This word consisits of small Latin letters, its length is no less that 1 and no more than 100 letters.  
  
### Output
If Vasya managed to say hello, print "`YES`", otherwise print "`NO`".

### Examples
```
Input
ahhellllloou
Output
YES
```
```
Input
hlelo
Output
NO
```


-----
## Solution

### Initial Thoughts
Just do a regex for hello.  
`\.*h\.*e\.*l\.*l\.*o`  
In my head I have c++ regex as slow however, so I can just implement it using regular c++ in a way which is still linear time.  
Just have a string containing `hello` and a counter containing how many of the characters you have seen. If you reach the end and the count is 5 then you have seen all of the characters. Otherwise, print `"NO"`.  

[chat_room.cpp](chat_room.cpp)  

Solved!  
