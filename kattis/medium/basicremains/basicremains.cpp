#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

ll convertToDecimal(string num, int base) {
	ll out = 0;
	for (int i=num.length()-1; i >= 0; i--) {
		out += (num[i] - '0') * pow(base, num.length()-1-i);
	}
	return out;
}

string convertFromDecimal(ll num, int base) {
	string output = "";
	while (num > 0) {
		char c = '0' + num % base;
		output = c + output; 
		num /= base;
	}
	return output;
}

string remainder(string a, string b, int base) {
	// convert them both to decimal then do it
	ll aNum = convertToDecimal(a, base);
	ll bNum = convertToDecimal(b, base);

	return convertFromDecimal(aNum % bNum, base);
}

bool lt(string a, string b, int base) {
	// remove leading zeros
	while (a[0] == '0') {
		a = a.substr(1, a.length()-1);
	}

	while (b[0] == '0') {
		b = b.substr(1, b.length()-1);
	}
	
	// compares if a is less than b if the number (represented as a string) is in the given base.
	if (a.size() > b.size()) 
		return false;
	if (a.size() < b.size())
		return true;

	for (int i=0; i<a.length(); i++) {
		if (a[i] < b[i]) {
			return true;
		} else if (a[i] > b[i]) {
			return false;
		}
	}
	
	// they are exactly equal
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int b;
	string p, m;
	cin >> b;
	while (b != 0) {
		cin >> p >> m;
		
		string working = "";
		// go through p, convert it to a number
		for (int i=0; i<p.length(); i++) {
			working += p[i];
			if (lt(working, m, b)) {
				continue;
			} else {
				// if they are equal then remainder becomes zero
				if (working == m) {
					working = "";
				} else {  // otherwise, find the remainder of this small section
					working = remainder(working, m, b);
				}
			}
		}
		if (working == "")
			cout << 0 << endl;
		else
			cout << working << endl;

		cin >> b;
	}

    return 0;
}
