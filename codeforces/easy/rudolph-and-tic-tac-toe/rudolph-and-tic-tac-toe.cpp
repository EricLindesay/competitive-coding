#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		vector<string> lines(3);
		cin >> lines[0] >> lines[1] >> lines[2];

		// look for horizontals
		char winner = '\0';
		for (int i=0; i<3; i++) {
			if (lines[i][0] == lines[i][1] && lines[i][1] == lines[i][2]) {
				if (lines[i][0] == '.')
					continue;

				winner = lines[i][0];
				break;
			}
		}
		if (winner != '\0') {
			cout << winner << "\n";
			continue;
		}

		// look for verticals
		for (int i=0; i<3; i++) {
			if (lines[0][i] == lines[1][i] && lines[1][i] == lines[2][i]) {
				if (lines[0][i] == '.')
					continue;

				winner = lines[0][i];
				break;
			}
		}
		if (winner != '\0') {
			cout << winner << "\n";
			continue;
		}

		// look for diagonals
		if (lines[0][0] == lines[1][1] && lines[1][1] == lines[2][2] && lines[0][0] != '.') {
			winner = lines[0][0];
			cout << winner << "\n";
			continue;
		}

		if (lines[0][2] == lines[1][1] && lines[1][1] == lines[2][0] && lines[0][2] != '.') {
			winner = lines[0][2];
			cout << winner << "\n";
			continue;
		}
		cout << "DRAW" << "\n";
	}

    return 0;
}
