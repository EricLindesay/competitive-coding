#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;

	vector<int> people(n);
	for (int &p : people) {
		cin >> p;
	}

	sort(people.begin(), people.end());

	int k = n/3;

	ll result = 0;
	for (int i=n-2; i>0; i-=2) {
		if (k <= 0) {
			break;
		}

		result += people[i];
		k--;
	}

	cout << result << endl;

    return 0;
}
