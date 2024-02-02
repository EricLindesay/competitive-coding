#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int *letters = new int[26] {0};

		for (char c : magazine) {
			letters[c-'a']++;
		}

		for (char c : ransomNote) {
			letters[c-'a']--;
			if (letters[c-'a'] < 0) {
				return false;
			}
		}
		return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution().canConstruct("a", "ba") << endl;
	cout << Solution().canConstruct("a", "b") << endl;

    return 0;
}
