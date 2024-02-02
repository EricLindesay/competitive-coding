#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
		int modulo = pow(10, 9) + 7;
		int length = 1;
		char current = s[0];
		s.append("\n");  // put a null char at the end just so we don't have to do anything
						 // at the end of the for loop

		ll count = 0;
		for (int i=1; i<s.size(); i++) {
			if (s[i] != current) {
				count = (count + (ll) (0.5*length*(length+1)))%modulo;
				current = s[i];
				length = 1;
			} else {
				length++;
			}
		}
		return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().countHomogenous("abbcccaa") << endl;
	cout << Solution().countHomogenous("xy") << endl;
	cout << Solution().countHomogenous("zzzzz") << endl;

    return 0;
}
