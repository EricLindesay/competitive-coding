#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


bool is_good(int n, list<int> a) {
	auto head = --a.end();
	auto tail = a.begin();
	int prev = -1;  // the thing says that 1 <= a[i] <= 2*10^5

	for (int i=0; i<n; i++) {
		int min_val = min(*tail, *head);
		if (i > 0) {
			if (min_val < prev) {  // at this point the array is not non-descending.
				return false;
			}
		}
		prev = min_val;
		if (min_val == *head)
			--head;
		else
			++tail;
	}
	return true;
}


int make_it_good(int n, list<int> a) {
	int actual_n = n;
	for (int i=0; i<n; i++) {
		if (is_good(actual_n, a)) return i;
		a.pop_front();
		actual_n--;
	}
	return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		list<int> a;
		for (int i=0; i<n; i++) {
			int num;
			cin >> num;
			a.push_back(num);
		}
		cout << make_it_good(n, a) << endl;
	}

    return 0;
}
