#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string s;
	cin >> s;
	string l, r;

	int chars[26] = {0};
	for (char &c : s) {
		chars[c-'A']++;
	}

	string middle = "";
	for (int i=0; i<26; i++) {
		if (chars[i] == 0) continue;
		
		if (chars[i]%2) {  // if theres an odd number of this character it must be middle
			if (middle.empty()) {
				middle = 'A'+i;
			} else {
				cout << "NO SOLUTION"; // if theres already a middle then no solution
				return 0;
			}
		} 
		chars[i]--;
		while (chars[i] > 0) {
			l += 'A'+i;
			r += 'A'+i;
			chars[i] -= 2;
		}
	}
	reverse(r.begin(), r.end());
	cout << l << middle << r << endl;

    return 0;
}
