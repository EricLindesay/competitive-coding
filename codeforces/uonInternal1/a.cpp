#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	ll x, y;
	cin >> s >> s >> s >> x >> s >> s >> y >> s >> s >> s;

	cout << "Alarm set for " << x*60*60+y*60 << " seconds from now." << endl;

    return 0;
}
