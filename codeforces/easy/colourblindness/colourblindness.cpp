#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	for (int i=0; i<t; i++) {
		ll n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		bool different = false;

		for (int j=0; j<n; j++) {
			if (s1[j] == 'R' && s2[j] != 'R') {
				different = true;
				break;
			}
			if (s2[j] == 'R' && s1[j] != 'R') {
				different = true;
				break;
			}
		}
		
		string ret = different? "NO":"YES";
		cout << ret << endl;
	}

    return 0;
}
