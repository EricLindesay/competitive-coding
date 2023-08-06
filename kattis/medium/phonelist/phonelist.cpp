#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool cmp(string &a, string &b) {
	return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

	while (t--) {
		map<string, bool> seen;
		bool correct = true;
		int n;
		cin >> n;

		vector<string> numbers(n);
		for (string &number : numbers) {
			cin >> number;
		}

		sort(numbers.begin(), numbers.end(), cmp);

		for (string number : numbers) {
			for (int i = 1; i <= number.length(); i++) {
				if (seen.count(number.substr(0, i)))
					correct = false;
			}

			seen[number] = true;
		}

		cout << ((correct) ? "YES" : "NO") << endl;
	}

    return 0;
}
