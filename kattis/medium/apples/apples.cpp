#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll r, c;
	cin >> r >> c;

	vector<vector<char>> grid(r, vector<char>(c, 0));
	for (int y=0; y<r; y++) {
		for (int x=0; x<c; x++) { 
			cin >> grid[y][x];
		}
	}

	for (int i=0; i<c; i++) {
		int numApples = 0;
		int hashPos = r;
		vector<int> hashes;
		vector<int> apples;
		// count the apples
		for (int j = 0; j<r; j++) {
			if (grid[j][i] == '#') {
				hashes.push_back(j);
				apples.push_back(numApples);
				numApples = 0;
			}
			if (grid[j][i] == 'a') {
				numApples++;
				grid[j][i] = '.';
			}
		}
		hashes.push_back(r);
		apples.push_back(numApples);

		// Now loop back up from the hash to ge tto the thing
		
		for (int h=0; h<hashes.size(); h++) {
			int numApples = apples[h];
			int j = hashes[h] - 1;
			while (j >= 0 && numApples > 0) {
				grid[j][i] = 'a';
				numApples--;
				j--;
			}
		}
	}

	for (int y=0; y<r; y++) {
		for (int x=0; x<c; x++) { 
			cout << grid[y][x];
		}
		cout << endl;
	}

    return 0;
}
