#include <bits/stdc++.h>
#include "myTimer.h"

typedef long long ll;

using namespace std;

Timer timer;
string tolower(string in) {
	timer.checkpoint("tolower");
	string out = "";
	for (char c : in) {
		out += tolower(c); 
	}
	return out;
}

int main() {
	timer.start();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string text;
	map<string, bool> seen;

	cout << "Before checkpoint" << endl;
	timer.checkpoint("Before while");
	cout << "After checkpoint" << endl;
	while (cin >> text) {
		timer.checkpoint("in while");
		string lower = tolower(text);
		if (seen.count(lower)) {
			cout << ". ";
		} else {
			cout << text << " ";
			seen[lower] = true;
		}
	}
	timer.print("in while");

    return 0;
}
