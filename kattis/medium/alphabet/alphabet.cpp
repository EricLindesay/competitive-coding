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

	if (str.size() == 0) {
		return 26;
	}

	int bestLength = INT32_MAX;
	string bestStr = "";
	int workingTotal = 1;
	string workingStr = "";
	workingStr += str[0];
	for (int i=1; i<str.length(); i++) {
		// Compare this and the previous, are they in order? Yes, then store the difference between them
		// No? Then save the working total if it is the best. Then reset working total and start counting again
		if (isInOrder(str[i-1], str[i])) {
			workingStr += str[i];
			cout << "Is in order " << str[i-1] << str[i] << endl;
			workingTotal += abs(str[i] - str[i-1]);
		} else {
			cout << "No longer in order" << endl;
			bestLength = min(bestLength, workingTotal);
			if (workingStr.size() > bestStr.size()) {
				bestStr = workingStr;
			}
			workingStr = "";
			workingStr += str[i];
			workingTotal = 1;
		}
	}
	if (workingStr.size() > bestStr.size()) {
		bestStr = workingStr; 
	}
	cout << bestStr << endl;
	bestLength = min(bestLength, workingTotal);

	cout << 26 - bestStr.size() << endl;
    return 0;
}
