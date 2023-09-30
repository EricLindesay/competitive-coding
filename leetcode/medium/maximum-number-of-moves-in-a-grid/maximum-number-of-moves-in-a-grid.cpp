#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
	map<int, int> cache;  // caches the posX, posY to moveNum returned. Caches maximum moveNum
	int moves(vector<vector<int>>& grid, int posX, int posY, int moveNum) {
		if (cache.count(posX*10000+posY)) {
			return cache[posX*10000+posY];
		}

		if (posX == grid[0].size()) {
			cache[posX*10000+posY] = moveNum - 1;
			return moveNum - 1;
		}
		if (posY < 0 || posY >= grid.size()) {
			return 0;
		}

		int moveTotal = moveNum;

		int m1=0, m2=0, m3=0;
		int current = grid[posY][posX];
		// if the next one is greater then go to it
//		cout << posX << ", " << posY << " = " << current << endl;
		if (posX + 1 < grid[0].size()) {  // are we at the left most column?
			if (posY - 1 >= 0 && grid[posY - 1][posX + 1] > current) {
//				cout << grid[posY - 1][posX + 1] << ">" << current << endl;
				m1 = moves(grid, posX+1, posY-1, moveNum + 1);
			}
			if (grid[posY][posX + 1] > current) {
//				cout << grid[posY][posX + 1] << ">" << current << endl;
			// Pos Y will be valid because we are already here
				m2 = moves(grid, posX+1, posY, moveNum + 1);
			}
			if (posY + 1 < grid.size() && grid[posY + 1][posX + 1] > current) {
//				cout << grid[posY + 1][posX + 1] << ">" << current << endl;
				m3 = moves(grid, posX+1, posY+1, moveNum + 1);
			}
//			cout << m1 << " " << m2 << " " << m3 << endl;
//			cout << endl;
		}

		moveTotal = max(moveTotal, m1);
		moveTotal = max(moveTotal, m2);
		moveTotal = max(moveTotal, m3);

		cache[posX*10000+posY] = moveTotal;
		return moveTotal;
	}

    int maxMoves(vector<vector<int>>& grid) {
		int moveMax = 0;
		for (int i=0; i<grid.size(); i++) {
			moveMax = max(moveMax, moves(grid, 0, i, 0));
		}
		return moveMax;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	//vector<vector<int>> moves = {{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
	//cout << Solution().maxMoves(moves) << endl;

	vector<vector<int>> moves2 = {{137,112,78,67},{76,65,122,135}};
	cout << Solution().maxMoves(moves2) << endl;
    return 0;
}
