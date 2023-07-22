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
    ll t;
    cin >> t;

	while (t--) {
		int w, h;
		string person;
		cin >> w >> h >> person;

		int vSteps = w - 1;
		int hSteps = h - 1;

		if (person == "Harry") {
			vSteps *= 2;
			hSteps--;
		} else {
			hSteps *= 2;
			vSteps--;
		}

		cout << vSteps << " " << hSteps << endl;

		string winner;
		if (vSteps > hSteps)
			winner = "Vicky";
		else if (hSteps < vSteps)
			winner = "Harry";
		else  // they are equal
			winner = person;

		cout << person;
		if (winner == person) {
			cout << " can win" << endl;
		} else {
			cout << " cannot win" << endl;
		}
	}

    return 0;
}
