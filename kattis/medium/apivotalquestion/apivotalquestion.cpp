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

int binary_search(vector<int>& a, int val) {
	int l = -1, r = a.size();
	while (r - l > 1) {
		    int m = (l + r) / 2;
			if (val < a[m]) {
				        r = m; // a[l] <= k < a[m] <= a[r]
							   //     
			} else {
				        l = m; // a[l] <= a[m] <= k < a[r]
							   //     
			}
			
	}
	return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> pivots;

    vector<int> inputs(n);
    for (int &i : inputs) {
        cin >> i;
    }
    // basically, go through the list and see if every value less than the current value is to the left
    // and all the values greater are to the right
    // For this you just need the max of the left and the min of the right

    // the issue is that you need to be able to update the right list with which mins you have
    // Would be more efficient to store it as ranges probably
    // Store it in a sorted vector and do a binary search I guess. This makes the algorithm O(nlogn) (due to sort)
    vector<int> sorted(inputs.size());
    partial_sort_copy(inputs.begin(), inputs.end(), sorted.begin(), sorted.end());

    int currentMax = 0;
    for (int i=0; i<inputs.size(); i++) {
        if (inputs[i] > currentMax) {  // don't need >= since the values are unique
            if (sorted.size() > 0 && inputs[i] <= sorted[0]) {  // is the current value less than the lowest in the right set?
                pivots.push_back(inputs[i]);
            }
            currentMax = inputs[i];
        }
        // Remove this value from the right sorted group
		auto it = sorted.begin() + binary_search(sorted, inputs[i]);
        //auto it = find(sorted.begin(), sorted.end(), inputs[i]);  // Should replace this with a binary search - Time it to see which is better
        sorted.erase(it);  // this probably isn't the best data structure since it will result in a lot of rearranging
    }

    cout << pivots.size();
    // Only print the first 100 of the pivot values
    for (int i=0; i<min(100, (int) pivots.size()); i++) {
        cout << ' ' << pivots[i];
    }

    return 0;
}
