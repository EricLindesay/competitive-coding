#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
		int out = 0;
		vector<int> g(garbage.size(), 0);
		vector<int> m(garbage.size(), 0);
		vector<int> p(garbage.size(), 0);
        
		for (int i=0; i<garbage.size(); i++) {
			for (char c: garbage[i]) {
				switch (c) {
					case 'G':
						g[i]++;
						break;
					case 'M':
						m[i]++;
						break;
					case 'P':
						p[i]++;
						break;
				}
			}
		}

		bool seenG = false;
		bool seenM = false;
		bool seenP = false;
		for (int i=garbage.size()-1; i >= 0; i--) {
			out += g[i] + p[i] + m[i];
			if (seenG) {
				out += travel[i];
			}
			if (seenP) {
				out += travel[i];
			}
			if (seenM) {
				out += travel[i];
			}
			if (g[i]) {
				seenG = true;
			}
			if (p[i]) {
				seenP = true;
			}
			if (m[i]) {
				seenM = true;
			}
		}
		return out;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<string> g {"G", "P", "GP", "GG"};
	vector<int> t {2, 4, 3};
	cout << Solution().garbageCollection(g, t) << endl;

    return 0;
}
