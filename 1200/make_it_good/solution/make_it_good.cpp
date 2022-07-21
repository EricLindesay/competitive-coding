#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_good(int n, vector<int> a) {
	vector<int> good_arr(n);
	int head = n-1;
	int tail = 0;
	for (int i=0; i<n; i++) {
		int min_val = min(a[tail], a[head]);
		if (i > 0) {
			if (min_val < good_arr[i-1]) {  // at this point the array is not non-descending.
				return false;
			}
		}
		good_arr[i] = min_val;
		if (min_val == a[head])
			head--;
		else
			tail++;
	}
	return true;
}


int make_it_good(int n, vector<int> a) {
	//cout << n << ": ";
	int actual_n = n;
	for (int i=0; i<n; i++) {
		//cout << a[i] << " ";
		if (is_good(actual_n, a)) return i;
		a.erase(a.begin());
		actual_n--;
	}
	
	cout << "Check is good " << is_good(n, a) << endl;
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
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];	
		}
		cout << make_it_good(n, a) << endl;
	}

    return 0;
}
