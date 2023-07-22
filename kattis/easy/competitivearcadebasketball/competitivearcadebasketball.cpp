#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p, m;
    cin >> n >> p >> m;

	map<string, int> participants;

	while (n--) {
		string name;
		cin >> name;
		participants[name] = 0;
	}

	bool isWinner = false;
	while (m--) {
		string name;
		int score;
		cin >> name >> score;
		participants[name] += score;
		if (participants[name] >= p) {
			isWinner = true;
			cout << name << " wins!" << endl;
			participants[name] = INT32_MIN;
		}
	}

	if (!isWinner) {
		cout << "No winner!" << endl;
	}

    return 0;
}
