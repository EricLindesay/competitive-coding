#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
    // https://open.kattis.com/problems/cocktail
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, T;
    cin >> N;
    cin >> T;

    vector<ll> potions;
    for (int i = 0; i < N; i++)
    {
        ll val;
        cin >> val;
        potions.push_back(val);
    }
    sort(potions.rbegin(), potions.rend());

    bool possible = true;
    for (int i = 0; i < N - 1; i++)
    {
        // Go through each potion, make sure you have enough time to drink the rest
        int number_of_potions_after = N - i - 1;
        if (potions[i] <= number_of_potions_after * T)
        {
            // Could have done a return in here and print "NO" immediately
            possible = false;
            break;
        }
    }
    if (possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
