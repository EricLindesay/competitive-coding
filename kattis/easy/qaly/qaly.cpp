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
    int t;
    cin >> t;

	double ans = 0;
	while (t--) {
		double a, b;
		cin >> a >> b;
		ans += a * b;
    }
	cout << ans;

    return 0;
}
