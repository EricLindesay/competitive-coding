#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

    int l, r;

    while (t--) {
        l = 2;
        r = 10;
        bool haveMovedL = false;
        bool movingL=false, movingR=true;
        while (l != r && !haveMovedL) {
            // see if its in the first half of the ruler
            cout << "? " << l << " " << r << endl;
            cout.flush();

            int ans;
            cin >> ans;

            if (movingR && ans == l*r) {  // if its what we expected, its in the upper half
                l *= 2;
                r *= 2;
                r++;
                movingL = true;
                movingR = false;
                haveMovedL = true;
            } else if (movingL && ans == (l+1)*(r+1)) {
                // we have overshot
                l /= 2;
                l--;
                r /= 2;
                movingR = true;
                movingL = false;
            } else {  // otherwise its in the current half
                if (movingR) { 
                    r /= 2;
                } else if (movingL) {
                    l *= 2;
                }
            }
        }
        cout << "! " << l << endl;
        cout.flush();
    }

    return 0;
}
 