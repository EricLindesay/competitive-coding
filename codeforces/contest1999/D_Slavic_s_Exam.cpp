#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;
        int p1 = 0;  // position in a
        int p2 = 0;  // position in b
        string ans = "";

        if (b.size() > a.size()) {
            cout << "NO" << endl;
            continue;
        }

        while (p1 < a.size() && p2 < b.size()) {
            if (a[p1] == '?' || a[p1] == b[p2]) {
                if (a[p1] == '?')
                    ans += b[p2];
                else
                    ans += a[p1];
                p1++;
                p2++;
            } else {
                ans += a[p1];
                p1++;
            }
        }
        if (p2 != b.size()) {
            cout << "NO" << endl;
        } else {
            while (p1 < a.size()) {
                if (a[p1] == '?')
                    ans += 'a';
                else 
                    ans += a[p1];
                p1++;
            }
            cout << "YES" << endl << ans << endl;
        }
    }

    return 0;
}
