#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int width, height;
    cin >> width >> height;
	if (width == 1 && height == 1) {
		cout << "Beata" << endl;
		return 0;
	}

	int numMoves = max(width/2, 1) * max(height/2, 1);
	string winner = (numMoves % 2) ? "Alf" : "Beata";
	cout << winner << endl;
    return 0;
}
