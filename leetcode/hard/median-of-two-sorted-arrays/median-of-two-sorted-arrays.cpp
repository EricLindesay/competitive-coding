#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
		int p2 = 0;
		int totalLength = nums1.size() + nums2.size();
		while (p1 + p2 < totalLength/2) {
			if (p1 >= nums1.size()) {
				p2++;
				continue;
			}
			if (p2 >= nums2.size()) {
				p1++;
				continue;
			}
			if (nums1[p1] < nums2[p2]) {
				p1++;
			} else {
				p2++;
			}
		}

		double median;
		if (nums1[p1] < nums2[p2]) {
			median = nums1[p1++];
		} else {
			median = nums2[p2++];
		}
		cout << median << endl;
		cout << p1 << " " << p2 << endl;
		if (totalLength%2 == 0) {
			// Find the next one along and do the average
			median = (median + min(nums1[p1], nums2[p2]))/2.0;
		}
		return median;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> num1 {1, 3};
	vector<int> num2 {2};
	cout << Solution().findMedianSortedArrays(num1, num2) << endl;
	vector<int> num3 {1, 2};
	vector<int> num4 {3, 4};
	cout << Solution().findMedianSortedArrays(num3, num4) << endl;

    return 0;
}
