#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainders(60, 0);  // the result of n1 + n2 % 60. Stores how many it has seen with this remainder
		int pairs = 0;
		for (int &num: time) {
			// see how much you need to add to get it to a multiple of 60
			// check if that is in the remainders array
			// if it is, add the count from the array, otherwise do nothing
			int other = (60 - num%60)%60;
			pairs += remainders[other];
			remainders[num%60]++;
		}
		return pairs;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> nums = {30, 20, 150, 100, 40};
	cout << Solution().numPairsDivisibleBy60(nums) << endl;

	vector<int> nums1 = {60, 60, 60};
	cout << Solution().numPairsDivisibleBy60(nums1) << endl;
    return 0;
}
