#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;

	int coffee = 0;
	int lectures = 0;
	for (char c : s) {
		if (c == '0' && coffee == 0) {
			continue;
		}

		if (c == '1') {
			lectures++;
			coffee = 2;
		}

		if (c == '0' && coffee > 0) {
			lectures++;
			coffee--;
		}
	}
	cout << lectures << endl;

    return 0;
}
