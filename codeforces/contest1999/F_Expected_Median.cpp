#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    int n, k;

    while (t--) {
        cin >> n >> k;

        int ones = 0;
        int zeros = 0;
        while (n--) {
            int num;
            cin >> num;
            if (num == 1) {
                ones++;
            } else {
                zeros++;
            }
        }
        cout << ones << " " << zeros << endl;
    }

    return 0;
}
 