#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	int n;
	while (t--) {
		cin >> n;
		vector<int> nums(n);
		for (int &i : nums) {
			cin >> i;
		}
		bool possible = true;
		for (int i=1; i<nums.size()-1; i++) {
			if (nums[i-1] > 0) {
				nums[i+1] -= nums[i-1];
				nums[i] -= nums[i-1]*2;

				if (nums[i] < 0 || nums[i-1] < 0) {
					possible = false;
					break;
				}
				nums[i-1] = 0;
			}
		}

		if (!possible) {
			cout << "no" << endl;
			continue;
		}

		// Check they are all zero
		for (int i=0; i<nums.size(); i++) {
			if (nums[i] != 0) {
				possible = false;
				break;
			}
		}
		cout << ((possible) ? "yes" : "no") << endl;
	}

    return 0;
}
