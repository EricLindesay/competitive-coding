#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef long long ll;

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
    // https://open.kattis.com/problems/airconditioned
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;


	vector<pair<int, int>> minions;
    for (int i = 0; i < N; i++)
    {
        ll L, U;
        cin >> L;
        cin >> U;
		minions.push_back({L, U});
    }

	sort(minions.begin(), minions.end(), cmp);

	int rooms = 1;
	int threshold = minions[0].second;

	for (int i=1; i<minions.size(); i++) {
		// if it is within the threshold then we are happy
		// otherwise create a new room and update the threshold
		if (minions[i].first > threshold) { 
			// We aren't happy
			threshold = minions[i].second;
			++rooms;
		}
	}

	printf("%d\n", rooms);

    return 0;
}
