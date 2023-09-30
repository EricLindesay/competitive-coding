#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<string> lines(3);
	cin >> lines[0] >> lines[1] >> lines[2];

	for (int i=0; i<3; i++) {
		// check horizontal
		if (lines[i][0] == lines[i][1] && lines[i][1] == lines[i][2]) {
			if (lines[i][0] == 'O') {
				cout << "Jebb";
				return 0;
			}
		}

		// check vertical
		if (lines[0][i] == lines[1][i] && lines[1][i] == lines[2][i]) {
			if (lines[0][i] == 'O') {
				cout << "Jebb";
				return 0;
			}
		}
	}

	// check forward slash
	if (lines[2][0] == lines[1][1] && lines[1][1] == lines[0][2]) {
		if (lines[2][0] == 'O') {
			cout << "Jebb";
			return 0;
		}
	}
	
	// check backwards slash
	if (lines[0][0] == lines[1][1] && lines[1][1] == lines[2][2]) {
		if (lines[0][0] == 'O') {
			cout << "Jebb";
			return 0;
		}
	}

	cout << "Neibb";

    return 0;
}
