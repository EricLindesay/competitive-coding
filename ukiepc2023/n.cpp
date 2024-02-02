#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
	map<double, string> sizes;
	map<string, double> names;
	vector<char> name;
	name.push_back('a');

	for (int i=0; i<n; i++) {
		double l;
		cin >> l;
		char ignore;
		cin >> ignore;

		if (sizes.count(l) > 0) {
			cout << sizes[l] << endl;
		} else {
			string s = "";
			for (char c : name) {
				s += c;
			}
			if (*name.rbegin() == 'z') {
				name.push_back('a');
			} else {
				char c = *name.rbegin();
				name.pop_back();
				name.push_back(c+1);
			}
			sizes[l] = s;
			names[s] = l;
			cout << s << endl;
		}
	}
	
    return 0;
}
