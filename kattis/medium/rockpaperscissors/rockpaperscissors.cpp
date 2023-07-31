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

	map<string, string> beats;
	beats["rock"] = "scissors";
	beats["paper"] = "rock";
	beats["scissors"] = "paper";

	int n, k;
	cin >> n;
	while (n != 0) {
		cin >> k;
		vector<vector<int>> players(n, vector<int>(2, 0));  // player[i]'s win, losses
		// for the next kn(n-1)/2 lines, there will be IO

		int formula = k * n * (n-1) / 2;
		while (formula--) {
			int p1, p2;
			string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2;
			p1--;
			p2--;
			if (m1 == m2)  // we don't care about draws
				continue;
			
			if (beats[m1] == m2) {  // p1 wins, p2 loses
				players[p1][0]++;
				players[p2][1]++;
			} else {  // p2 wins, p1 loses
				players[p2][0]++;
				players[p1][1]++;
			}
		}

		// Output each player's win percentage
		for (vector<int> player : players) {
			double total = player[0]+player[1];
			if (total == 0) {
				printf("-\n");
			} else {
				printf("%.3lf\n", player[0]/total);
			}
		}

		// look for next time's
		cin >> n;
		if (n != 0)  // if it isn't the last one, print a newline -- not sure if this is necessary for submission to pass
			cout << endl;
	}

    return 0;
}
