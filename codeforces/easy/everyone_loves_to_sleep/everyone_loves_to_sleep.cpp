#include <iostream>

using namespace std;

int distance(long long h, long long m, long long hi, long long mi) {
	long long dist = (hi*60)+mi - ((h*60)+m);
	
	if (dist < 0) {
		dist = 1440+(dist%1440);
	} else {
		dist = dist%1440;
	}
	return dist;
}

int a() {
	long long n, h, m;
	long long ansh = -1, ansm = -1;
	cin >> n >> h >> m;
	for (long long i=0; i<n; i++) {
		long long hi, mi;
		cin >> hi >> mi;
		long long mins = distance(h, m, hi, mi);
		if (mins < ansh*60+ansm || (ansh == -1 && ansm == -1)) {
			ansh = mins/60;
			ansm = mins%60;
		}
	}

	cout << ansh << " " << ansm << "\n";
	return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

	for (long long i=0; i<t; i++) {
		a();
	}

    return 0;
}
