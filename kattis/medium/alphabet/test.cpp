#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

bool isInOrder(char one, char two) {
//	if (alphabet[two - 'a'] == 0)
//		return false;

	// you have to see if any of the following characters are valid
	// you could have   `acdefg`, it is valid to put a `b` in between the `a` and `c`
	//return (alphabet[one - 'a'] == alphabet[two - 'a' - 1]);
	return (one - 'a' < two - 'a');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string str;
	cin >> str;

	// O(n^2) - choose each character as the starting one, see how many you have to remove
	// Should be fast enough since there are only 50 inputs.
	// need to do some dynamic programming thing
	int bestLength = 0;
	for (int i=0; i<str.length(); i++) {
		char prevChar = str[i];
		int currentLength = 1;
		cout << "Start anew " << str[i];
		for (int j=i+1; j<str.length(); j++) {
			if (isInOrder(prevChar, str[j])) {
				prevChar = str[j];
				++currentLength;
				cout << str[j];
			}
		}
		cout << endl;
	    bestLength = max(bestLength, currentLength);
	}
	cout << 26 - bestLength << endl;

    return 0;
}
