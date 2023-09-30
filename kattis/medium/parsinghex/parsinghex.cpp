#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string line;

	while (cin >> line) {
		string hexString = "";
		int i = 0;
		while (i < line.length()) {
			if (line[i] == '0' && tolower(line[i+1]) == 'x' && hexString.length() < 10) {
				hexString += line[i];
				hexString += line[i+1];
				// read in as many hex characters as you can
				i += 2;
				while (i < line.length() && isxdigit(line[i])) {
					hexString += line[i];
					i++;
				}
				cout << hexString << " " << strtol(hexString.c_str(), NULL, 16) << endl;
				hexString = "";
			}
			i++;
		}
	}

    return 0;
}
