#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n, m, a;
	scanf("%lld %lld %lld", &n, &m, &a);

	long long ans = 0;
	ans = ceil((long double) n/a) * ceil((long double) m/a);
	printf("%lld", ans);
	return 0;
}
