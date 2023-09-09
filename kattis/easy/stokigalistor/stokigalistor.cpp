#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	vector<int> nums(t);
	vector<int> original(t);
	for (int i=0; i<t; i++) {
		int num;
		cin >> num;
		nums[i] = num;
		original[i] = num;
	}

	sort(nums.begin(), nums.end());

	int out = 0;
	for (int i=0; i<t; i++) {
		if (nums[i] != original[i])
			out++;
	}
	cout << out;

    return 0;
}
