# include <iostream>
# include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	bool first_char = true;
	bool change = true;
	string ns;
	string fixed_string;
	getline(cin, ns);

	for (char n : ns) {
		// see if all caps except first
		if (first_char) {
			first_char = false;
			if (islower(n))
				fixed_string += toupper(n);
			else
				fixed_string += tolower(n);
		}	
		else {
			if (islower(n)) {
				change = false;
				break;
			}
			fixed_string += tolower(n);
		}
	}

	if (change)
		cout << fixed_string;
	else
		cout << ns;
    return 0;
}
