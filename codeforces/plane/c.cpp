#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// contest/1968/problem/C
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	
	while (t--) {
		int n, m;  // length and number of updates
		cin >> n >> m;
		cout << n << " " << m << endl;
		string s;
		cin >> s;
		cout << s << endl;

		vector<int> updates(m);
		for (int &i : updates) {
			cin >> i;
			cout << i << " ";
		}
		cout << endl;

		string c;
		cin >> c;
		cout << c << endl << endl;

		sort(c.begin(), c.end());
		sort(updates.begin(), updates.begin());
		
		int c_ind = 0;
		int u_ind = 0;
		string out = "";
		
		for (int i=0; i<s.size(); i++) {
			// Is there an update which matches this?
			// If there is, add the updated one to out
			// Otherwise, just add it to out
			while (u_ind < updates.size() && updates[u_ind] > i) {
				u_ind++;
			}
			if (updates[u_ind] == i) {
				// There is one which is the correct index
				out += c[c_ind];
				c_ind++;
			} else {
				out += s[i];
			}
		}

		/*for (int i=0; i<m; i++) {
			if (i+1 < m && updates[i] == updates[i+1]) {
				continue;  // don't care about duplicates
			}
			// replace the index that it says with the smallest element in c.
			// The smallest element in c is c[c_ind] (then increment ind)
			s[updates[i]] = c[c_ind];
			cout << "It updates to " << c[c_ind] << endl;
			c_ind++;
		}
		cout << s << endl;*/
		cout << out << endl;
	}

    return 0;
}
