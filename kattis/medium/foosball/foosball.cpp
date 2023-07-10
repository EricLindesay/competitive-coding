#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
	queue<string> names;

	while (n--) {
		string name;
		cin >> name;
		names.push(name);
	}

	string wo = names.front();
	names.pop();
	string bo = names.front();
	names.pop();
	string wd = names.front();
	names.pop();
	string bd = names.front();
	names.pop();

	pair<string, string> whiteOrder {wo, wd};
	pair<string, string> blackOrder {bo, bd};

	string wins;
	cin >> wins;

	int longest_streak = 0;
	int current_streak = 0;
	char winners = '\0';
	vector<pair<string, string>> streakers;
	for (auto it=wins.begin(); it != wins.end(); it++) {
		if (*it == 'W') {
			// scoring team swap positions
			string t = wd;
			wd = wo;
			wo = t;

			// losing team
			names.push(bd);  // defence gets removed
			bd = bo;  // defence becomes the previous offence
			bo = names.front();  // defender defecates
			names.pop();
			blackOrder = make_pair(bd, bo);
		} else {
			// scoring team swap positions
			string t = bd;
			bd = bo;
			bo = t;

			// losing team
			names.push(wd);  // defence gets removed
			wd = wo;  // defence becomes the previous offence
			wo = names.front();  // defender defecates
			names.pop();
			whiteOrder = make_pair(wd, wo);
		}
		if (winners == *it) {
			current_streak++;
			if (current_streak == longest_streak) {
				if (winners == 'W')
					streakers.push_back(whiteOrder);
				else {
					streakers.push_back(blackOrder);
				}
			} else if (current_streak > longest_streak) {
				longest_streak = current_streak;
				streakers.clear();
				if (winners == 'W')
					streakers.push_back(whiteOrder);
				else
					streakers.push_back(blackOrder);
			}
		} else {
			winners = *it;
			current_streak = 1;
			if (current_streak == longest_streak) {
				if (winners == 'W')
					streakers.push_back(whiteOrder);
				else {
					streakers.push_back(blackOrder);
				}
			} else if (current_streak > longest_streak) {
				longest_streak = current_streak;
				streakers.clear();
				if (winners == 'W')
					streakers.push_back(whiteOrder);
				else
					streakers.push_back(blackOrder);
			}
		}
	}
	
	for (pair<string, string> streak : streakers) {
		printf("%s %s\n", streak.first.c_str(), streak.second.c_str());
	}

    return 0;
}
