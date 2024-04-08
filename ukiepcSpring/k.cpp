#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int pymod(int n, int m) {
	return (((n%m)+m)%m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin >> s;
	int x=0, y=0;

	for (char c : s) {
		switch (c) {
			case 'N':
				y++;
				break;
			case 'S':
				y--;
				break;
			case 'E':
				x++;
				break;
			case 'W':
				x--;
				break;
		}
	}

	if (pymod(x, 2) || pymod(y, 2)) {
		cout << "NO" << endl;
		return 0;
	}

	int hx=0, hy=0, rx=0, ry=0;

	string output = "";
	bool isHeli = false;
	bool isRover = false;
	for (char c : s) {
		if (c == 'N') {
			if (hy < ry) {
				hy++;
				output += 'H';
				isHeli = true;
			} else {
				ry++;
				output += 'R';
				isRover = true;
			}
		} else if (c == 'S') {
			if (hy > ry) {
				hy--;
				output += 'H';
				isHeli = true;
			} else {
				ry--;
				isRover = true;
				output += 'R';
			}
		} else if (c == 'E') {
			if (hx < rx) {
				hx++;
				output += 'H';
				isHeli = true;
			} else {
				rx++;
				output += 'R';
				isRover = true;
			}
		} else if (c == 'W') {
			if (hx > rx) {
				hx--;
				output += 'H';
				isHeli = true;
			} else {
				rx--;
				output += 'R';
				isRover = true;
			}
		}
	}
	if (hx == rx && hy == ry && isHeli && isRover) {
		cout << output << endl;
	} else {
		cout << "NO" << endl;
	}

    return 0;
}
