#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 21;
    int out = 0;
    while (t--) {
        string s;
        cin >> s;
        int ones = 0;
        for (char c : s) {
            ones += c-'0';
        }
        if (ones >= 11) {
            out++;
        }
    }
    cout << out << endl;    

    return 0;
}
