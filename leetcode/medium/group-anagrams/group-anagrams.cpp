#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> anagrams;

		for (string str : strs) {
			string sorted = str;
			sort(sorted.begin(), sorted.end());
			anagrams[sorted].push_back(str);
		}

		vector<vector<string>> output;
		for (pair<string, vector<string>> a : anagrams) {
			output.push_back(a.second);
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
