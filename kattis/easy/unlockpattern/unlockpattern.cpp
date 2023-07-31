#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<pair<int, int>> coords(9);

	int inputs = 9;
	double length = 0;
	int x = 0;
	int y = 0;
	while (inputs--) {
		int num;
		cin >> num;
		
		coords[num-1] = {x, y};

		if (++x == 3) {
			x = 0;
			++y;
		}
	}

	for (int i=1; i<9; i++) {
		int xCoord = coords[i].first;
		int yCoord = coords[i].second;
		int prevX = coords[i-1].first;
		int prevY = coords[i-1].second;
		
		double dist = sqrt(pow(xCoord - prevX, 2) + pow(yCoord - prevY, 2));	
		length += dist;
	}
	printf("%.6lf", length);

    return 0;
}
