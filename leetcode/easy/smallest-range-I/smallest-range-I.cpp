#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

typedef long long ll;

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
		if (nums.size() == 1)
			return 0;

		int smallest = INT32_MAX;
		int largest = INT32_MIN;
		
		// Look for smallest and largest
		for (int i=0; i<nums.size(); i++) {
			smallest = min(smallest, nums[i]);
			largest = max(largest, nums[i]);
		}
		int difference = abs(largest - smallest);
		int distance = difference - 2 * k; 

		return max(distance, 0);
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<int> b {0, 10};
	vector<int> c {1, 3, 6};
	vector<int> d {-2, 3, 4};
	vector<int> e {2, 7, 2};
	vector<int> f {3, 1, 10};
	cout << Solution().smallestRangeI(b, 2) << endl;
	cout << Solution().smallestRangeI(c, 3) << endl;
	cout << Solution().smallestRangeI(d, 3) << endl;
	cout << Solution().smallestRangeI(e, 1) << endl;
	cout << Solution().smallestRangeI(f, 4) << endl;

	cout << endl << "Expected: 6, 0, 0, 3, 1" << endl;
    return 0;
}
