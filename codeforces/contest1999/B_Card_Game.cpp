#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    int a1, a2, b1, b2;
    while (t--) {
        cin >> b1 >> b2 >> a1 >> a2;

        int games = 0;
        if (a1 < b1) {
            if (a2 <= b2) {
                games++;
            }
        }
        if (a1 == b1) {
            if (a2 < b2) {
                games++;
            }
        }
        if (a1 < b2) {
            if (a2 <= b1)
                games++;
        }
        if (a1 == b2) {
            if (a2 < b1)
                games++;
        }
        if (a2 < b1) {
            if (a1 <= b2)
                games++;
        }
        if (a2 == b1) {
            if (a1 < b2)
                games++;
        }
        if (a2 < b2) {
            if (a1 <= b1)
                games++;
        }
        if (a2 == b2) {
            if (a1 < b1)
                games++;
        }
        cout << games << endl;
    }

    return 0;
}
