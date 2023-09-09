#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> prefix(n, 1);
		vector<int> suffix(n, 1);

		for (int i=1; i<n; i++) {
			prefix[i] = prefix[i-1] * nums[i-1];  // the prefix of this number is the prefix of the previous number times that number
			suffix[n - i] = suffix[n-i+1] * nums[n-i+1];
		}
		
        vector<int> output(n, 1);
		for (int i=0; i<n; i++) {
			output[i] = prefix[i] * suffix[i];
		}

		return output;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {

	}

    return 0;
}
