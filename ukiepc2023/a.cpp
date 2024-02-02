#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, w;
	cin >> n >> w;

	int q = 0;
	while (n > 0) {
		cout << w << " " << q << endl;
		q++;
		n--;
	}


    return 0;
}
