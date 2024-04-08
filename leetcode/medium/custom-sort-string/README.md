# Custom Sort String
- [Problem](#problem)
- [Solution](#solution)

## Problem
[Problem link](https://leetcode.com/problems/custom-sort-string)

### Description
You are given two strings `order` and `s`. All the characters of `order` are **unique** and were sorted in some custom order previously.

Permute the characters of `s` so that they match the order that `order` was sorted. More specifically, if a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.

Return *any permutation of *`s`* that satisfies this property*.

### Input


- `1 <= order.length <= 26`
- `1 <= s.length <= 200`
- `order` and `s` consist of lowercase English letters.
- All the characters of `order` are **unique**.




### Examples

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
Input:  <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> order = "cba", s = "abcd" </span>

Output:  <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> "cbad" </span>

Explanation:  `"a"`, `"b"`, `"c"` appear in order, so the order of `"a"`, `"b"`, `"c"` should be `"c"`, `"b"`, and `"a"`.

Since `"d"` does not appear in `order`, it can be at any position in the returned string. `"dcba"`, `"cdba"`, `"cbda"` are also valid outputs.
</div>


<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
Input:  <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> order = "bcafg", s = "abcd" </span>

Output:  <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> "bcad" </span>

Explanation:  The characters `"b"`, `"c"`, and `"a"` from `order` dictate the order for the characters in `s`. The character `"d"` in `s` does not appear in `order`, so its position is flexible.

Following the order of appearance in `order`, `"b"`, `"c"`, and `"a"` from `s` should be arranged as `"b"`, `"c"`, `"a"`. `"d"` can be placed at any position since it's not in order. The output `"bcad"` correctly follows this rule. Other arrangements like `"bacd"` or `"bcda"` would also be valid, as long as `"b"`, `"c"`, `"a"` maintain their order.
</div>


## Solution

[custom-sort-string.cpp](./custom-sort-string.cpp)
Solved!