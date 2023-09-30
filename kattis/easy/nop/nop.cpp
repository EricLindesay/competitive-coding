#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	char c;
	int i = 0;
	int additions = 0;
	while (cin >> c) {
		if (isupper(c)) {
			if (i%4) {
				additions += 4 - i%4;
				i += 4 - i%4;
			}
			// otherwise we can just add the command as normal
		}
		i++;
	}
	cout << additions << endl;

    return 0;
}
