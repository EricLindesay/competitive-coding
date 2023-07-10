#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		return haystack.find(needle);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cout << Solution().strStr("adbutsad", "sad") << ": 5" << endl;
	cout << Solution().strStr("a", "sad") << ": -1" << endl;
	cout << Solution().strStr("leetcode", "leeto") << ": -1" << endl;

    return 0;
}
