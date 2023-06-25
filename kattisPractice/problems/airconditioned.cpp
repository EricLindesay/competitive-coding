#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
	// https://open.kattis.com/problems/airconditioned
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	vector<vector<int>> temperatures(2 * N + 1, vector<int>(0));

	vector<pair<int, int>> minions;
	int num_minions = N;
	for (int i = 0; i < N; i++)
	{
		ll L, U;
		cin >> L;
		cin >> U;
		for (int j = L; j < U + 1; j++)
		{
			temperatures[j].push_back(i);
		}
		minions.push_back({L, U});
	}

	int rooms = 0;
	while (num_minions > 0)
	{
		for (int i = 0; i < temperatures.size(); i++)
		{
			cout << temperatures[i].size() << " ";
		}
		cout << endl;

		// find the max, remove it from the thing, see whats left
		int max_coverage = 1;
		int pos = 0;
		for (int i = 0; i < 2 * N + 1; i++)
		{
			if (max_coverage < (int)temperatures[i].size())
			{
				max_coverage = temperatures[i].size();
				pos = i;
			}
		}
		// if max_coverage is still 1, return the number of minions remaining. We know at this point
		// that there is one minion to each room
		if (max_coverage == 1)
		{
			rooms += num_minions;
			break;
		}

		rooms++;

		// Otherwise, remove the minions in that room and see what changes
		for (int i = 0; i < max_coverage; i++)
		{
			// reduce the temperature of the rooms the minion covered
			int minion_index = temperatures[pos][0];
			pair<int, int> minion = minions[minion_index];

			// Loop through the rooms the minion affected
			for (int j = minion.first; j <= minion.second; j++)
			{
				// find the position of minion index
				auto pos = find(temperatures[j].begin(), temperatures[j].end(), minion_index);

				// Remove the minion from that room, reducing temperature by 1
				temperatures[j].erase(pos);
			}
			num_minions--;
		}
	}
	printf("%d\n", rooms);

	return 0;
}
