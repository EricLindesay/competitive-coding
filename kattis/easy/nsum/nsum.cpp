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
    int n;
    cin >> n;

	int ans = 0;
    for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		ans += num;
    }
	cout << ans;

    return 0;
}
