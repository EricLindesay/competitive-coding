#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

void subseq(int c1, int c2, string v, vector<string> &ans, int n) {
	if (c1 == n) {
		while (c2++ < n) { // add the remaining ")"
			v += ")";
		}
		ans.push_back(v);
		return;
	}

	// open a new bracket because we can
	subseq(c1+1, c2, v+"(", ans, n);

	if (c2 < c1) { // try the scenario where you close the bracket now as well
		subseq(c1, c2+1, v+")", ans, n);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string v;
	subseq(0, 0, v, ans, n);
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<string> s = generateParenthesis(4);
	for (string i : s) {
		cout << i << endl;
	}

    return 0;
}
