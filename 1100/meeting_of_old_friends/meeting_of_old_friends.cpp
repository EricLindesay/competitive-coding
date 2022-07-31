#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;

	long long right_val = min(r1, r2);
	long long left_val = max(l1, l2);
	long long size_of_intersection = right_val - left_val + 1;
	if (left_val <= k && k <= right_val)
		size_of_intersection--;
	if (size_of_intersection < 0)
		size_of_intersection = 0;
	cout << size_of_intersection;

    return 0;
}
