#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;

	vector<char> seen_chars(str.length());
	
	int count = 0;
	for (char c: str) {
		if (find(seen_chars.begin(), seen_chars.end(), c) == seen_chars.end()) {
			seen_chars.push_back(c);
			count += 1;
		}
	}

	if (count%2) {
		cout << "IGNORE HIM!";
	} else {
		cout << "CHAT WITH HER!";
	}

    return 0;
}
