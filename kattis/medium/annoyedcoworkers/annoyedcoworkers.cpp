#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>

typedef long long ll;

using namespace std;

class Compare {
public:
	bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b) {
		return a.first+a.second > b.first+b.second;
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int h, c;
	cin >> h >> c;

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> coworkers;

	ll highestAnnoyance = 0;
	while (c--) {
		ll a, d;
		cin >> a >> d;
		highestAnnoyance = max(highestAnnoyance, a);
		coworkers.push({a, d});
	}

	while (h--) {
		pair<ll, ll> coworker = coworkers.top();
		coworkers.pop();

		ll annoyance = coworker.first + coworker.second;
		highestAnnoyance = max(highestAnnoyance, annoyance);
		coworkers.push({annoyance, coworker.second});
	}

	cout << highestAnnoyance << endl;

    return 0;
}
