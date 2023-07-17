#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<int> chessSet(6);
	for (auto &x : chessSet) 
		cin >> x;

	vector<int> expected {1, 1, 2, 2, 2, 8};
	for (int i=0; i<6; i++) {
		cout << expected[i] - chessSet[i] << " ";
	}

    return 0;
}
