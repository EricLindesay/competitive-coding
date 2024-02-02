#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
	string invert(string a) {
		string inverted = "";
		for (char &c : a) {
			if (c == '0')
				inverted.push_back('1');
			else
				inverted.push_back('0');
		}
		return inverted;
	}

	string recursion(int n) {
		if (n == 1) {
			return "0";
		}

		string s = recursion(n-1);
		string inverted = invert(s);
		reverse(inverted.begin(), inverted.end());

		return s + "1" + inverted;
	}

    char findKthBit(int n, int k) {
		// You could preprocess the 20 strings and then just look up
		return recursion(n)[k-1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().findKthBit(3, 1) << endl;
	cout << Solution().findKthBit(4, 11) << endl;

    return 0;
}
