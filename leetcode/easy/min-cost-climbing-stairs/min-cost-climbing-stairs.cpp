#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void printVector(vector<int> &vect) {
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
    }
	cout << endl;
}

class Solution {
public:
	int minCostClimbingStairs(vector<int> &cost) {
		vector<int> ans(cost.size() + 1, -1);
		ans[0] = 0;
		for (int i = 0; i < cost.size(); i++) {
			// sort out the cost for the next two cells
			if (ans[i + 1] == -1)  // if its -1, then just overwrite it
				ans[i + 1] = ans[i] + cost[i];
			else
				ans[i + 1] = min(ans[i + 1], ans[i] + cost[i]);  // otherwise check if its better
			if (i < cost.size() -1)  // for +2, you don't need to check if its -1, it always will be
				ans[i + 2] = ans[i] + cost[i + 1];
		}
		return min(ans[ans.size() - 1], ans[ans.size() - 2]);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// vector<int> cost {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	vector<int> cost{0, 0, 0, 0};
	cout << Solution().minCostClimbingStairs(cost) << endl;

	return 0;
}
