#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution
{

private:
	map<string, bool> words;
	map<string, vector<string>> cache;

	vector<string> helper(string s)
	{
		if (cache.count(s))
		{
			return cache[s];
		}

		if (s.size() == 0)
		{ // if we are at the end then return ""
			return {""};
		}

		vector<string> ret = {};
		for (int i = 1; i <= s.size(); i++)
		{
			string start = s.substr(0, i);
			if (words.count(start))
			{
				// it is a valid word
				vector<string> out = helper(s.substr(i, s.size()));
				for (string s : out)
				{
					if (s.size() == 0)
					{
						ret.push_back(start);
					}
					else
					{
						ret.push_back(start + " " + s);
					}
				}
			}
		}

		cache[s] = ret;
		return ret;
	}

public:
	vector<string> wordBreak(string s, vector<string> &wordDict)
	{
		// Put the dict in the map
		for (string word : wordDict)
		{
			words[word] = 1;
		}

		return helper(s);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
	vector<string> out = Solution().wordBreak("catsanddog", wordDict);
	for (string s : out)
	{
		cout << s << " ||| ";
	}
	cout << endl;

	return 0;
}
