#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
	int denominator = 0;
	int numerator = 0;
	while (n--) {
		int num;
		cin >> num;
		if (num > -1) {
			numerator += num;
			denominator++;
		}
	}

	printf("%lf", (double) numerator/denominator);

    return 0;
}
