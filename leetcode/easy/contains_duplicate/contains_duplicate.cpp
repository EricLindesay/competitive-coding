#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		map<int, bool> seen;
		
		for (int num : nums) {
			if (seen.count(num)) {
				return true;
			} else {
				seen[num] = 1;
			}
		}
		return false;
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
