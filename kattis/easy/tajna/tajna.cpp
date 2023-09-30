#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int getRows(int n) {
	int rt = floor(sqrt(n));
	while (n%rt != 0) {
		rt--;
	}
	return rt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string encoded;
    cin >> encoded;

	if (encoded.size() == 1) {
		cout << encoded << endl;
		return 0;
	}

	int rows = getRows(encoded.size());
	int cols = encoded.size()/rows;

	string decoded = "";
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			int index = x * rows + y;
			// could directly print the character here and it would work but lets leave it for clarity
			decoded += encoded[index];
		}
	}
	cout << decoded << endl;

    return 0;
}
