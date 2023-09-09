#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {

	}

    return 0;
}
