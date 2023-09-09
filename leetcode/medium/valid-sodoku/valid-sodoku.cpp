#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		// check rows and columns
		for (int y=0; y<9; ++y) {
			vector<bool> col(9, false);
			vector<bool> row(9, false);
			for (int x=0; x<9; ++x) {
				char row_val = board[y][x];
				char col_val = board[x][y];
				if (row_val != '.') {
					if (row[row_val])  // there is a duplicate in this row
						return false;
					row[row_val] = true;
				}
				if (col_val != '.') {
					if (col[col_val])
						return false;
					col[col_val] = true;
				}
			}
		}

		// check the 3x3 grids
		for (int y=0; y<9; y += 3) {
			for (int x=0; x<9; x += 3) {
				vector<bool> square(9, false);
				for (int y1=0; y1<3; ++y1) {
					for (int x1=0; x1<3; ++x1) {
						int val = board[y + y1][x+x1];
						if (val == '.')
							continue;

						if (square[val])
							return false;
						square[val] = true;
					}
				}
			}
		}
		return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {

	}

    return 0;
}
