#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll au, bu, ar, br;
	cin >> au >> bu >> ar >> br;

	ll solutions = 0;
	if (au > 0) {
		if (br > 0) {
			solutions += au;
			au = 0;
		} else {
			ll add = min(au, bu);
			solutions += min(au, bu);
			au -= add;
			bu -= add;
		}
	}
	if (bu > 0) {
		if (ar > 0) {
			solutions += bu;
			bu = 0;
		} else {
			ll add = min(au, bu);
			solutions += min(au, bu);
			au -= add;
			bu -= add;
		}
	}
	solutions += ar * br;

	cout << solutions;

    return 0;
}
