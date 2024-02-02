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
    vector<int> getRow(int rowIndex) {
		vector<int> prevRow{1};
		if (rowIndex == 0) {
			return prevRow;
		}
		vector<int> currentRow;  // could use nCr to work it out but no
		for (int i=2; i<=rowIndex+1; i++) {
			currentRow.resize(i);
			currentRow[0] = 1;
			currentRow[currentRow.size() - 1] = 1;

			for (int j=1; j<i-1; j++) {
				currentRow[j] = prevRow[j-1] + prevRow[j];
			}
			prevRow = currentRow;
		}
		return currentRow;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> a = Solution().getRow(5);
	for (int b : a) {
		cout << b << ", ";
	}
	cout << endl;

    return 0;
}
