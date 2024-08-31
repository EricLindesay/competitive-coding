#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool check(string start, string &pattern) {
	if (start.length() < pattern.length())
		return false;

	for (int i=0; i<pattern.length(); i++) {
		if (start[i] != pattern[i])
			return false;
	}
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s, p;
	cin >> s >> p;

	ll ans = 0;
	for (int i=0; i<s.length(); i++) {
		if (check(s.substr(i), p))
			ans++;
	}
	cout << ans;

    return 0;
}
