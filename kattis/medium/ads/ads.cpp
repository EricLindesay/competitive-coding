#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool validChar(char c) {
	return (('A' <= c && c <= 'Z') || // Uppercase
                ('a' <= c && c <= 'z') || // Lowercase
                ('0' <= c && c <= '9') || // Number
                c == '?' || c == '!' || c == ',' || c == '.' || c == ' ');// Other
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h;
	cin >> h >> w;
	cin.ignore(256, '\n');

	char grid[h][w];
	for (int i=0; i<h; i++) {
		string s;
		getline(cin, s);
		for (int j=0; j<w; j++) {
			grid[i][j] = s[j];
		}
	}

	vector<vector<int>> ads;  // [[x, y, w, h]]

	// Go through the current line. Is there an ad?
	for (int y=0; y<h; y++) {
		for (int x=0; x<w; x++) {
			if (!validChar(grid[y][x]) && grid[y][x] != '+') {
				// you have a bad character, now we have to find the position of the ad
				// and the width and height
				// and then we can just fill it with blanks
				// find all of the top left +'s, then use those to find the bottom right.
				// then find what ad you are in 
				// find left
				int t = y;
				int l = x;
				while (!(grid[t][l] == '+' && grid[t][l] == '+' && grid[t][l] == '+')) {
					while (grid[t][l] != '+') {
						--l;
					}
					while (t >= 0 && grid[t][l] == '+') {
						--t;
					}
					++t;
				}
				// find the bottom right 
				// Right now you have top left
				int b = t;
				int r = l;
				while (r < w && grid[t][r] == '+')
					++r;
				--r;  // we go one too far by accident

				while (b < h && grid[b][r] == '+')
					++b;
				--b;  // we go one too far by accident
				
				// fill that area with blank
				for (int i=l; i<=r; i++) {
					for (int j=t; j <= b; j++) {
						grid[j][i] = ' ';
					}
				}
				x = r;
				y = b;
			}
		}
	}

	// print the grid
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}

    return 0;
}
