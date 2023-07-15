#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	int ans;
	cin >> ans;  // the first one is unmodified
    for (int i = 1; i < t; i++) {
		int num;
		cin >> num;
		ans += num-1;
    }
	cout << ans;

    return 0;
}
