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
	vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);

        for (int i=1; i<temperatures.size(); i++) {
            if (temperatures[i] > temperatures[i-1]) {
                // Loop backwards and update the answer
                int j = i-1;
                cout << "Start backwards loop " << i << ": " << temperatures[i] << endl;
                while (j >= 0 && temperatures[i] > temperatures[j]) {
                    if (ans[j]) {
                        j--;
                        continue;
                    }
                    cout << "\tWe are at " << temperatures[j] << endl;
                    ans[j] = i - j;
                    j--;
                }
            }
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {73,74,75,71,69,72,76,73};
    vector<int> b = Solution().dailyTemperatures(a);

    for (int c : b) {
        cout << c << ", ";
    }
    cout << endl;

    return 0;
}
