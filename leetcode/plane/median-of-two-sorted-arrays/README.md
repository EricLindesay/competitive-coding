Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/
Hard

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

Example 2:
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

Example 3:
```
Input: nums1 = [1, 2, 3, 4, 5, 6], nums2 = [7, 8, 9, 10]
Output: 5
Explanation: merged array = [1,2,3,4,5,6,7,8,9] and median is 5
```
3.5, 8.5
3.5 < 8.5, get the upper half of the first one
8.5 > 3.5, get the lower half of the second one

5, 7
5 < 7, get the upper half of the first one  -- this logic is wrong. 
7 > 5, get the lower half of the second one, oh wait, we stop because there is nothing in the lower half.

Example 4:
```
Input: nums1 = [1, 4, 6, 7], nums2 = [2, 3, 6, 9]
Output: 5
Explanation: merged array = [1, 2, 3, 4, 6, 6, 7, 9] and median is 5
```
[1, 4, 6, 7] [2, 3, 6, 9]
5, 4.5
5 > 4.5, find lower half of first array
4.5 < 5, find upper half of second array

[1, 4] [6, 9]
2.5, 7.5
upper half of first
lower half of second

4, 9


Constraints:
- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -10^6 <= nums1[i], nums2[i] <= 10^6


```py
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
```

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};
```


# Solution
Find the median of each array, then use binary search to recursively find the median?
This doesn't work.
Maybe do binary search on one array at a time?
Maybe you also need to keep track of how many middles you have visited.