# Find the Town Judge
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/find-the-town-judge)

### Description
In a town, there are `n` people labeled from `1` to `n`. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

<ol>
	- The town judge trusts nobody.
	- Everybody (except for the town judge) trusts the town judge.
	- There is exactly one person that satisfies properties **1** and **2**.
</ol>

You are given an array `trust` where `trust[i] = [a<sub>i</sub>, b<sub>i</sub>]` representing that the person labeled `a<sub>i</sub>` trusts the person labeled `b<sub>i</sub>`. If a trust relationship does not exist in `trust` array, then such a trust relationship does not exist.

Return *the label of the town judge if the town judge exists and can be identified, or return *`-1`* otherwise*.

### Input


- `1 <= n <= 1000`
- `0 <= trust.length <= 10^4`
- `trust[i].length == 2`
- All the pairs of `trust` are **unique**.
- `a<sub>i</sub> != b<sub>i</sub>`
- `1 <= a<sub>i</sub>, b<sub>i</sub> <= n`




### Examples
```
Input: n = 2, trust = [[1,2]]
Output: 2
```

```
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
```

```
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```


## Solution

[find-the-town-judge.cpp](./find-the-town-judge.cpp)

Solved!
