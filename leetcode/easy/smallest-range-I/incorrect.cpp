#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
		if (nums.size() == 1)
			return 0;
		int minimum = INT32_MAX;
		int maximum = INT32_MIN;
		int second_highest = INT32_MIN;
		int second_lowest = INT32_MAX;

		for (int num: nums) {
			if (num <= minimum) {
				second_lowest = minimum;
				minimum = num;
			}
			if (num > minimum && num < second_lowest) {
				second_lowest = num;
			}
			if (num >= maximum) {
				second_highest = maximum;
				maximum = num;
			} 
			if (num < maximum && num > second_highest) {
				second_highest = num;
			}
		}

		int upper_k = maximum - second_highest;
		int lower_k = abs(minimum - second_lowest);
		int u = min(upper_k, k);
		int l = min(lower_k, k);
		return (maximum - u) - (minimum + l);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<int> a {1};
	vector<int> b {0, 10};
	vector<int> c {1, 3, 6};
	vector<int> d {-2, 3, 4};
	vector<int> e {2, 7, 2};
	cout << Solution().smallestRangeI(a, 0) << endl;
	cout << Solution().smallestRangeI(b, 2) << endl;
	cout << Solution().smallestRangeI(c, 3) << endl;
	cout << Solution().smallestRangeI(d, 3) << endl;
	cout << Solution().smallestRangeI(e, 1) << endl;

    return 0;
}
