#include <iostream>
#include <vector>

using namespace std;


bool is_integer(double num) {
	return (int) num == num;
}


long long integer_points() {
	// read in inputs.
	long long n;
	cin >> n;
	vector<long long> p(n);
	for (int i=0; i<n; i++) {
		long long num;
		cin >> num;
		p[i] = num;
	}
	long long m;
	cin >> m;

	//vector<long long> q(n);
	//for (int i=0; i<m; i++) {
	//	long long num;
	//	cin >> num;
	//	q[i] = num;
//	}
	// this still reads in input but also has other stuff
	long long ans = 0;
	for (int i=0; i<m; i++) {
		long long qi;
		cin >> qi;
		for (long long pi: p) {
			double x_coord = (double) 0.5 * (qi-pi);
			double y_coord = x_coord + pi;
			if (is_integer(x_coord) && is_integer(y_coord)) {
				ans++;
			}
		}
	}

	return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
	
	for (int i=0; i<t; i++) {
		cout << integer_points() << endl;
	}

    return 0;
}
