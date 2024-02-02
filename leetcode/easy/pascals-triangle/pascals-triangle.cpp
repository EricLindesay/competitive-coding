#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
		out.push_back(vector<int>{1});
		recurse(out, numRows - 1);
		return out;
    }

	void recurse(vector<vector<int>> &out, int numRows) {
		if (numRows == 0) {
			return;
		}

		int prevRow = out.size()-1;
		vector<int> newRow(out.size()+1);
		newRow[0] = 1;
		newRow[newRow.size()-1] = 1;
		for (int i=1; i<newRow.size()-1; i++) {
			// Add the two above
			newRow[i] = out[prevRow][i-1] + out[prevRow][i];
		}
		out.push_back(newRow);
		recurse(out, numRows - 1);
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<vector<int>> a = Solution().generate(5);
	for (vector<int> b : a) {
		cout << "[";
		for (int c : b) {
			cout << c << ",";
		}
		cout << "]" << endl;
	}
	cout << endl;

    return 0;
}
