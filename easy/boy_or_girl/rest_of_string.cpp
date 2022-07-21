#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;

	int count = 0;
	for (int i=0; i<str.length(); i++) {
		// Loop through the rest of the string to see if it occurs again,
		// if it does then we don't want to consider it.
		// This value will instead be considered when it gets to the last occurance
		// of that character.
		bool distinct = true;
		for (int j=i+1; j<str.length(); j++) {
			if (str[j] == str[i]) {
				distinct = false;
				break;
			}
		}
		if (distinct) {
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
