#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> eleFreq;
		for (int num: nums) {
			if (eleFreq.count(num)) {
				++eleFreq[num];
			} else {
				eleFreq[num] = 1;
			}
		}

		// create a vector of pairs, Freq -> element
		// sort it based on frequency
		// take top k
		vector<pair<int, int>> pairs;
		for (pair<int, int> e : eleFreq) {
			pairs.push_back({e.second, e.first});
		}
		sort(pairs.rbegin(), pairs.rend());

		// look at the last k
		vector<int> output(k);
		for (int i=0; i<k; i++) {
			output[i] = pairs[i].second;
		}
		return output;
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
