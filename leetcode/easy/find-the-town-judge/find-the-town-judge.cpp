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
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> isJudge(n+1, true);
        vector<int> trusts(n+1, 0);
        for (vector<int> &a : trust) {
            isJudge[a[0]] = false;
            trusts[a[1]]++;
        }
        for (int i=1; i<=n; i++) {
            if (isJudge[i] && trusts[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution(). << endl;

    return 0;
}
