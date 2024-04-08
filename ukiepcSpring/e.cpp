#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// DP[j] = max happiness for `j` spent

    ll t;
    cin >> t;
	ll T, d;
	while (t--) {
		cin >> T >> d;
		int hoursn = d/60;
		int startHour = T/60;
		double hsPerc = startHour/12.0f;

		int startMinute = T%60;
		double msPerc = startMinute/60.0f;

		d %= 60;
		cout << "It initially goes around " << hoursn << " times" << endl;

		double hend = startHour + d/60.0f;
		double hePerc = hend/12.0f;
		if (hePerc > 1) hePerc--;

		double mend = startMinute + d;
		double mePerc = mend/60.0f;
		if (mend > 1) mend--;

		// Now just see, will it overlap at some point within this time?
		// Ans = hoursn + 1 or hoursn
		if (msPerc < hsPerc && mePerc >= hePerc) {
			hoursn++;
		} else if (msPerc > hsPerc && mePerc >= hePerc && mePerc < msPerc) {
			hoursn++;
		}

		cout << hoursn << endl;
	}

    return 0;
}
