#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> cups(n);
	for (int &cup : cups)
		cin >> cup;

	int v;
	cin >> v;

	vector<int> pours(cups[0]+1, -1);
	pours[cups[0]] = 0; // it is always possible to get to N with 0 pours, you just do nothing
	
	// Add the next cup
	for (int i=1; i<n; i++) {
		// Look at the already possible pours. Add in the new possibilities
		for (int j=cups[i]; j<pours.size(); j++) {
			if (pours[j] > -1) {
				if (pours[j-cups[i]] == -1)
					pours[j-cups[i]] = pours[j] + cups[i];
				else
					pours[j-cups[i]] = min(pours[j-cups[i]], pours[j]+cups[i]);
			}
		}
	}

	for (int i=0; i<=cups[0]; i++) {
		cout << pours[i] << " ";
	}
	cout << endl;

	if (pours[v] == -1) {
		cout << "impossible";
	} else
		cout << pours[v];

    return 0;
}
