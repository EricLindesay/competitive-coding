#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll log3(ll a) {
    // log3 = log2(a) / log2(3)
    return log2(a)/log2(3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, l, r;
    cin >> t;

    while (t--) {
        cin >> l >> r;

        // Try to get a number to 0 asap, it doesn't really matter about the other numbers
        ll turns = 0;

        ll smallest_log = log3(l)+1;
        // This is how many times it took to get to zero for the first one. Double it because you have to
        // undo that much from a larger number
        turns += smallest_log*2;

        l++;

        while (l <= r) {
            // find next power of three
            ll nextThree = pow(3, log3(l)+1);  

            // All numbers between the current and the next power of three have the same value for
            // log3(n). So calculate how many values we have (take note, you don't want to go over
            // `r` hence the minimum)
            turns += (log3(l)+1)*(min(nextThree, r+1) - l);

            l = nextThree;
        }

        cout << turns << endl;
    }

    return 0;
}
