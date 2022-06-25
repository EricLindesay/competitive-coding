#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long tables;
	long long r, g, b;
	scanf("%64lld %64lld %64lld", &r, &g, &b);

	long long total = r+g+b;
	long long average = total/3;
	long long sum_smallest_two = total - max({r, g, b});

	tables = min({sum_smallest_two, average});
	printf("%lld", tables);
	return 0;
}
