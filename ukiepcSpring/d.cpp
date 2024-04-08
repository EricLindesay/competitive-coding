#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin >> s;

	string fhalf = s.substr(0, s.size()/2);
	string shalf = s.substr(s.size()/2);

	sort(fhalf.begin(), fhalf.end());
	sort(shalf.begin(), shalf.end());
	if (fhalf == shalf) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
    return 0;
}
