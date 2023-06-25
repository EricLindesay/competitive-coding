#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin >> s;
	string hello = "hello";
	int ind = 0;
	for (char c : s) {
		if (hello[ind] == c) {
			ind++;
			if (ind == 5) {
				break;
			}
		}
	}

	if (ind == 5) {
		cout << "YES";
	} else {
		cout << "NO";
	}
    return 0;
}
