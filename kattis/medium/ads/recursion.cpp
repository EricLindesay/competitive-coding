#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool validChar(char c) {
	return (('A' <= c && c <= 'Z') || // Uppercase
                ('a' <= c && c <= 'z') || // Lowercase
                ('0' <= c && c <= '9') || // Number
                c == '?' || c == '!' || c == ',' || c == '.' || c == ' ');// Other
}

void foundAd(vector<vector<char>> &grid, int w, int h, int l, int t) {
	// loop through the ad. The first row you can use to find the width of the ad.
	// The next rows you can use to find bad characters, if you find a bad character start filling
	// if you find another ad, use recursion
	int r = l;
	while (r < w && grid[t][r] == '+') {
		++r;
	}
	r--;
	
	int b = t;
	while (b < h && grid[b][l] == '+') {
		++b;
	}
	b--;

	// loop through the rest to find more ads and if it has invalid characters
	bool containsInvalid = false;
	for (int y1=t+1; y1<b; ++y1) {  // we have already checked the first row
		for (int x1=l+1; x1<r; ++x1) {  // we don't need to check the left and right borders
			// if there is an invalid character, we need to stop and just fill
			if (!validChar(grid[y1][x1])) {
				if (grid[y1][x1] == '+') {  // if there is a plus, then use recursion
					// find bottom right
					foundAd(grid, w, h, x1, y1);
				}
				else {  // otherwise there is an invalid character so stop and start filling
					containsInvalid = true;
					break;			
				}
			}
		}
	}
	if (containsInvalid) {
		// fill from the top up to the end with whitespace
		for (int y1=t; y1<=b; y1++) {
			if (grid[y1][r] != '+') {
				break;
			}
			// fill this array in the correct places with whitespace
			for (int x1=l; x1 <= r; x1++) {
				grid[y1][x1] = ' ';
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h;
	cin >> h >> w;
	cin.ignore(256, '\n');

	// read in input
	vector<vector<char>> grid(h, vector<char>(w));
	for (int i=0; i<h; i++) {
		string s;
		getline(cin, s);
		for (int j=0; j<w; j++) {
			grid[i][j] = s[j];
		}
	}

	// Go through the current line. Is there an ad?
	int x = 0, y = 0;
	string outputline = "";
	while (x < w && y < h) {
		if (grid[y][x] == '+') {
			// it is the start of an ad
			foundAd(grid, w, h, x, y);
		}
		outputline.push_back(grid[y][x]);
		if (++x >= w) {  // reset x
			x = 0;
			++y;
			cout << outputline << endl;
			outputline = "";
		}
	}

    return 0;
}
