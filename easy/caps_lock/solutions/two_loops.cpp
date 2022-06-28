# include <iostream>
# include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	bool first_char = true;
	bool change = true;
	string ns;
	getline(cin, ns);

	for (char n : ns) {
		// see if all caps except first
		if (first_char) {
			first_char = false;
		}
		else
			if (islower(n)) {
				change = false;
				break;
			}
	}

	first_char = true;
	for (char s : ns) {
		if (!change) cout << s;
		else {
			// capitalise first char
			// lower case all others.
			if (first_char) {
				first_char = false;
				if (islower(s))
					cout << (char) toupper(s);
				else
					cout << (char) tolower(s);
			} else
				cout << (char) tolower(s);
		}
	}
    return 0;
}
