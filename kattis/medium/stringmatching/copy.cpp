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

	string needle;
	string haystack;
	while (getline(cin, needle)) {
		getline(cin, haystack);

		for (int i=0; i<haystack.length() - needle.length() + 1; i++) {
			bool found = true;
			for (int j=0; j<needle.length(); j++) {
				if (haystack[i] != needle[j]) {
					found = false;
					break;
				}
			}
			if (found) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
 

    return 0;
}
