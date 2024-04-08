#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    long double a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        long double val;
        char dol;
        while (a--) {
            cin >> val >> dol;
            if (cin.fail() || b <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            // Multiply val by 100 to treat it as an integer
            long long int val_int = static_cast<long long int>(val * 100);
            
            // Round val_int up to the nearest multiple of c
            long long int diff = (val_int + c - 1) / c;
            diff = floor(diff);
            
            b -= diff*c - val_int;
        }
        if (b <= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}