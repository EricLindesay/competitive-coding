#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
		while (i >= 0 && (num[i]-'0')%2 == 0) {
			i--;
		}
		return num.substr(0, i+1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().largestOddNumber("52") << endl;
	cout << Solution().largestOddNumber("4206") << endl;
	cout << Solution().largestOddNumber("35427") << endl;

    return 0;
}
