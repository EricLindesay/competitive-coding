#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, m;
    cin >> n >> s >> m;
	--s;

	vector<int> board(n);
	vector<int> landed(n, 0);  // whether you have landed on this square yet or not
	for (auto &cell : board)
		cin >> cell;

	int hops = 0;
	while (true) {
		if (landed[s] == 1) {
			cout << "cycle\n" << hops << endl;
			break;
		}

		if (board[s] == m) {
			cout << "magic\n" << hops << endl;
			break;
		}

		if (s < 0) {
			cout << "left\n" << hops << endl;
			break;
		}

		if (s >= n) {
			cout << "right\n" << hops << endl;
			break;
		}

		landed[s] = 1;
		s += board[s];
		++hops;
	}

    return 0;
}
