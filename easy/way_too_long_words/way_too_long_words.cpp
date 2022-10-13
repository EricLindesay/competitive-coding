#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;

	for (int i=0; i<t; i++) {
		string s;
		cin >> s;
	
		if (s.size() <= 10)
			cout << s << endl;
		else
			cout << s[0] << s.size()-2 << s[s.size()-1] << endl; 
	}
	
	return 0;
}
