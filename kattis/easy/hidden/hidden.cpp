#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string p, s;
    cin >> p >> s;

	map<char, int> occurances;
	for (int i=0; i<p.length(); i++) {
		if (occurances.count(p[i])) {  // if its there
			occurances[p[i]]++; // increment
		} else {
			occurances[p[i]] = 1; // otherwise set to one
		}
	}

	int pi = 0;
	bool fail = false;
	for (int i=0; i<s.length(); i++) {
		// is s[i] == p[pi]? 
		// No see if s[i] is in the map, we cant have later ones first
		// Yes decrease the value in the map, increase pi, continue
		if (s[i] == p[pi]) {
			occurances[p[pi]]--;
			pi++;
		} else {
			if (occurances.count(s[i])) {  // if its in the amp
				if (occurances[s[i]] != 0) { // and it hasn't already been seen
					fail = true;
					break;
				}
			}
		}
	}

	if (fail || pi != p.length()) {
		cout << "FAIL";
	} else {
		cout << "PASS";
	}

    return 0;
}
