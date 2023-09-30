#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		bool wasRemoval = true; // whether there was a removal last loop
		while (!s.empty() && wasRemoval)
		{
			wasRemoval = false;
			// look for the string "abc"
			size_t pos = s.find("abc");
			if (pos != string::npos)
			{
				s = s.substr(0, pos) + s.substr(pos + 3, s.size());
				wasRemoval = true;
			}
		}
		return s.empty();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << Solution().isValid("aabcbc") << endl;
	cout << Solution().isValid("abcabcababcc") << endl;
	cout << Solution().isValid("abccba") << endl;

	return 0;
}
