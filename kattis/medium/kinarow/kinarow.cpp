#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	int hanselWins = 0;
	int gretelWins = 0;

	while (t--) {
		bool haveWinner = false;
		int m, n, k;
		cin >> m >> n >> k;

		vector<string> grid(n);
		for (string &row : grid) {
			cin >> row;
		}

		// check horizontals using sliding window
		for (int y=0; y < n; y++) {
			string window = "";
			int h = 0;
			int g = 0;
			for (int x=0; x < m; x++) {
				// sliding window
				char c = grid[y][x];
				if (window.length() == k) {  // remove the first element
					if (window[0] == 'x')
						h--;
					else if (window[0] == 'o')
						g--;

					window = window.substr(1, window.length()-1);
				} 
				// add on the new element
				window += c;
				if (c == 'x')
					h++;
				else if (c == 'o') 
					g++;

				if (h == k) {
					hanselWins++;
					haveWinner = true;
					break;
				} else if (g == k) {
					gretelWins++;
					haveWinner = true;
					break;
				}
			}
		}

		// check vertical using sliding window
		for (int x=0; x < n; x++) {
			string window = "";
			int h = 0;
			int g = 0;
			for (int y=0; y < m; y++) {
				// sliding window
				char c = grid[y][x];
				if (window.length() == k) {  // remove the first element
					if (window[0] == 'x')
						h--;
					else if (window[0] == 'o')
						g--;

					window = window.substr(1, window.length()-1);
				} 
				// add on the new element
				window += c;
				if (c == 'x')
					h++;
				else if (c == 'o') 
					g++;

				if (h == k) {
					hanselWins++;
					haveWinner = true;
					break;
				} else if (g == k) {
					gretelWins++;
					haveWinner = true;
					break;
				}
			}
		}

		// check positive positive diagonal on the y
		string window = "";
		int h = 0;
		int g = 0;
		for (int y=0; y < n; y++) {
			for (int x=0; x < m; x++) {
				// sliding window
				char c = grid[y][x];
				if (window.length() == k) {  // remove the first element
					if (window[0] == 'x')
						h--;
					else if (window[0] == 'o')
						g--;

					window = window.substr(1, window.length()-1);
				} 
				// add on the new element
				window += c;
				if (c == 'x')
					h++;
				else if (c == 'o') 
					g++;

				if (h == k) {
					hanselWins++;
					haveWinner = true;
					break;
				} else if (g == k) {
					gretelWins++;
					haveWinner = true;
					break;
				}
			}
		}
	}

    return 0;
}
