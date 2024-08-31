#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	int a, b;

	while (t--) {
		cin >> a >> b;

		int largest = max(a, b);
		int smallest = min(a, b);

		// if you were to reduce the largest one by two each time, how many does that reduce the smallest by?
		// Then work back upwards until you 
	}

    return 0;
}
