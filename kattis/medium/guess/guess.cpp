#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
	int low = 1;
	int high = 1000;
	string response;

	int guess = 500;
	cout << guess << endl;

	cin >> response;
	while (response != "correct") {
		if (response == "lower") {
			high = guess - 1;
		} else if (response == "higher") {
			low = guess + 1;
		}

		guess = (high+low)/2;
		cout << guess << endl;
		cin >> response;
	}

    return 0;
}
