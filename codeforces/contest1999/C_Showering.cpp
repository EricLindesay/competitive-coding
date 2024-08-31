#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

    int n, s, m;
    while (t--) {
        cin >> n >> s >> m;
        vector<pair<int, int>> ts(n);
        for (int i=0; i<n; i++) {
            int a, b;
            cin >> a >> b;
            ts[i] = make_pair(a, b);
        }
        sort(ts.begin(), ts.end());

        // Go through and find how much time you have
        int time = 0;
        bool found = false;
        for (int i=0; i<n; i++) {
            if (ts[i].first - time >= s) {
                found = true;
                break;
            } else {
                time = ts[i].second;
            }
        }
        if (m - time >= s) {
            found = true;
        }

        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
