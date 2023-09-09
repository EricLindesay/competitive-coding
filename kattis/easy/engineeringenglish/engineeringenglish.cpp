#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string tolower(string in) {
	string out = "";
	for (char c : in) {
		out += tolower(c); 
	}
	return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string text;
	map<string, bool> seen;

	while (cin >> text) {
		string lower = tolower(text);
		if (seen.count(lower)) {
			cout << ". ";
		} else {
			cout << text << " ";
			seen[lower] = true;
		}
	}

    return 0;
}
