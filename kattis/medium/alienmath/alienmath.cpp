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
    int base;
	cin >> base;

	map<string, int> mappings;
	for (int i=0; i<base; i++) {
		string s;
		cin >> s;
		mappings[s] = i;
	}

	string num;
	cin >> num;

	int result = 0;  // problem states that the base 10 will always be within 10^9 so no bignum
	// read through num and get the integer mapping
	string current_read = "";
	for (char c : num) {
		current_read.push_back(c);
		if (mappings.count(current_read)) {
			// We have found a number.
			result *= base;
			result += mappings[current_read];
			// Reset the current read
			current_read = "";
		}
	}

	cout << result << endl;

    return 0;
}
