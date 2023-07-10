#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

vector<vector<int>> keypad {
	{vector<int> {0}},  // 0
	{vector<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}},  // 1
	{vector<int> {0, 2, 3, 5, 6, 8, 9}},  // 2
	{vector<int> {3, 6, 9}},  // 3
	{vector<int> {0, 4, 5, 6, 7, 8, 9}}, // 4
	{vector<int> {0, 5, 6, 8, 9}},  // 5
	{vector<int> {6, 9}},  // 6
	{vector<int> {0, 7, 8, 9}},  // 7
	{vector<int> {0, 8, 9}},  // 8
	{vector<int> {9}},  // 9
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int closest_so_far = INT32_MAX;

		// check for single digits
		for (int k=0; k < keypad[1].size(); k++) {
			int value = keypad[1][k];
			int distance = abs(n - value);
			if (distance < abs(n - closest_so_far)) {
				closest_so_far = value;
			}
		}

		// check for double digits
		for (int j=0; j < keypad[1].size(); j++) {
			for (int k=0; k < keypad[j].size(); k++) {
				int value = 10 * keypad[1][j] + keypad[j][k];
				int distance = abs(n - value);
				if (distance < abs(n - closest_so_far)) {
					closest_so_far = value;
				}
			}
		}

		// check for triple digits
		for (int i=0; i < 3; i++) {  // 1 <= k <= 200
			for (int j=0; j < keypad[i].size(); j++) {
				for (int k=0; k < keypad[j].size(); k++) {
					int value = 100 * i + 10 * keypad[i][j] + keypad[j][k];
					int distance = abs(n - value);
					if (distance < abs(n - closest_so_far)) {
						closest_so_far = value;
					}
				}
			}
		}
		cout << closest_so_far << endl;
	}

    return 0;
}
