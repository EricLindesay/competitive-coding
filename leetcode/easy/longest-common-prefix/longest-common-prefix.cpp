#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		for (int i=0; i<strs[0].length(); i++) {
			char c = strs[0][i];
			for (string str: strs) {
				if (i == str.length())
					return strs[0].substr(0, i);

				if (str[i] != c)
					return strs[0].substr(0, i);
			}
		}
		// otherwise, all prefix characters are equal
		return strs[0];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<string> a {"flower", "flow", "flight"};
	vector<string> b {"dog", "racecar", "car"};

	cout << Solution().longestCommonPrefix(a) << endl;
	cout << Solution().longestCommonPrefix(b) << endl;

    return 0;
}
