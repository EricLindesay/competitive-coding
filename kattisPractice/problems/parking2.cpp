#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
    /*
    https://open.kattis.com/problems/parking2

    Find the distance between the first and last shop and double it.
    He has to walk that distance to be able to visit every shop and return home
    */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<int> shops;
        ll c;
        cin >> c;

        int _min = 0, _max = 99;
        for (int j = 0; j < c; j++)
        {
            int shop;
            cin >> shop;
            _min = max(_min, shop);
            _max = min(_max, shop);
        }
        cout << abs((_max - _min) * 2) << "\n";
    }

    return 0;
}
