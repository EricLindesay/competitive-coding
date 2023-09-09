#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string n1, n2;
	cin >> n1 >> n2;
	string output;

	// Loop through each of them backwards
	string::reverse_iterator i = n1.rbegin();
	string::reverse_iterator j = n2.rbegin();
	int carry = 0;

	// Add the two numbers together, one digit at a time
	while (i != n1.rend() && j != n2.rend()) {
		int addition = (*i) - '0' + (*j) - '0' + carry;
		carry = addition / 10;
		output += '0' + addition % 10;
		i++;
		j++;
	}

	// add in the rest of the numbers for the i (if there are any)
	while (i != n1.rend()) {
		int addition = (*i) - '0' + carry;
		carry = addition / 10;
		output += '0' + addition % 10;
		i++;
	}

	// add in the rest of the numbers for the j (if there are any)
	while (j != n2.rend()) {
		int addition = (*j) - '0' + carry;
		carry = addition / 10;
		output += '0' + addition % 10;
		j++;
	}

	// if there is still a carry, add it onto the end
	if (carry) {
		output += '0' + carry;
	}

	// the output is stored as the number reversed
	// reverse the output to get the right number
	reverse(output.begin(), output.end());
	cout << output; // print the number
    return 0;
}
