#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
	bool isArithmetic(vector<int> &arr) {
		if (arr.size() < 2) {
			return false;
		}

		int diff = arr[0] - arr[1];
		for (int i=2; i<arr.size(); i++) {
			if (arr[i-1] - arr[i] != diff) {
				return false;
			}
		}
		return true;
	}

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		vector<bool> output(l.size());
		for (int i=0; i<l.size(); i++) {
			vector<int> temp(nums.begin()+l[i], nums.begin()+r[i]+1);
			sort(temp.begin(), temp.end());
			output[i] = isArithmetic(temp);
		}
		return output;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> nums {4, 6, 5, 9, 3, 7};
	vector<int> l {0, 0, 2};
	vector<int> r {2, 3, 5};
	vector<bool> solutions = Solution().checkArithmeticSubarrays(nums, l, r);

	for (bool s : solutions) {
		cout << s << endl;
	}

    return 0;
}
