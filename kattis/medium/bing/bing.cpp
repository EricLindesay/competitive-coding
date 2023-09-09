#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	map<string, int> prefixes;

	while (t--) {
		string word;
		cin >> word;

		string subword = "";
		for (char c : word) {
			subword.push_back(c);
			auto found = prefixes.find(subword);
			if (found != prefixes.end())  // it's found
				++found->second;
			else 
				prefixes[subword] = 1;
		}

		cout << prefixes[word] - 1 << endl;  // we included the original word in the map already so drecrease by one to account for this
	}

    return 0;
}
