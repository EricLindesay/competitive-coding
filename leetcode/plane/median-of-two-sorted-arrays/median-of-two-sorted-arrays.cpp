#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
		int mid1 = nums1[nums1.size()/2];
		int mid2 = nums2[nums2.size()/2];

		// you've found the midpoint of each array. Now use binary search to find the median
		// if the sum of the lengths is of odd size, you have to add a half.
    }
};


int main() {
	vector<int> vect1 {1, 3};
	vector<int> vect2 {2};
	cout << Solution().findMedianSortedArrays(vect1, vect2) << endl;
}
