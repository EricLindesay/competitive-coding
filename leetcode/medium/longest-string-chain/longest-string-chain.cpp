#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool cmp(const string &a, const string &b) {
	return (a.size() < b.size());
}

class Solution {
private:
	map<string, vector<string>> successors;

	bool isPredecessor(string sshort, string slong) {
		// sshort = shorter string
		// slong = longer string
	
		// If the lengths don't differ by one character, they aren't
		if (sshort.size() + 1 != slong.size()) {
			return false;
		}

		// Use two pointers to traverse
		int sp = 0;  // pointer for short
		int lp = 0;  // pointer for long
		bool seen_diff = false;
		while (sp < sshort.size() && lp < slong.size()) {
			if (sshort[sp] == slong[lp]) {  // if they are the same character just increment
				sp++;
				lp++;
			} else {
				// If you haven't seen any difference yet then this is the first
				// Otherwise, this is the second so stop looking
				if (!seen_diff) {
					seen_diff = true;
					lp++;
					continue;
				} else {
					return false;
				}
			}
		}

		return (sp == sshort.size() && lp >= slong.size() - 1);
	}

	void sizeSort(vector<string> &words) {
		sort(words.begin(), words.end(), cmp);
	}

	void print(vector<string> &words) {
		for (string word : words) {
			cout << word << " ";
		}
		cout << endl;
	}

	map<string, int> cache;
	int getDepth(string &root, int depth = 1) {
		if (cache.count(root)) {
			return cache[root];
		}

		cache[root] = depth;

		// Go thorugh each of the successors
		// find the successor's depth
		// return the max of these depths
		int maxDepth = depth;
		for (string &s : successors[root]) {
			maxDepth = max(getDepth(s, depth+1), maxDepth);
		}

		return maxDepth;
	}
	
public:
    int longestStrChain(vector<string>& words) {
		sizeSort(words);

		for (int i=0; i<words.size(); i++) {
			for (int j=i+1; j<words.size(); j++) {
				if (words[j].size() == words[i].size())
					continue;
				if (words[j].size() != words[i].size() + 1)
					// we only want to consider direct predecessors
					break;

				// Compare whether these two words are predecessors and store it in the map
				if (isPredecessor(words[i], words[j])) {
					successors[words[i]].push_back(words[j]);
				}
			}
		}


		// Now recursively traverse the map (DFS) to find the highest depth
		
		// go through each of the words
		// find their depth
		// Use hashing for the depth
		int maxDepth = 0;
		for (string &s : words) {
			maxDepth = max(maxDepth, getDepth(s));
		}

		return maxDepth;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<string> l1 = {"a","b","ba","bca","bda","bdca"};
	cout << Solution().longestStrChain(l1) << endl;

	vector<string> l2 = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
	cout << Solution().longestStrChain(l2) << endl;

	vector<string> l3 = {"abcd", "dbqca"};
	cout << Solution().longestStrChain(l3) << endl;
    return 0;
}
