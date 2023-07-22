#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;

	map<string, pair<string, int>> friends;  // birthday : <name, friendship value>
	while (n--) {
		// read in the data
		string name, birthday;
		int value;
		cin >> name >> value >> birthday;

		// see if someone already has that birthday
		if (friends.count(birthday)) {
			// if they do, compare the friendship value
			// get friendship value
			int getValue = friends[birthday].second;
			if (value > getValue) {  // if they like this friend more, overwrite
				friends[birthday] = {name, value};
			}
		} else {
			// no one else has it, just add it
			friends[birthday] = {name, value};
		}
	}
	
	// get all the friends and sort it alphabetically
	priority_queue<string, vector<string>, greater<string>> pq;
	for (auto it = friends.begin(); it != friends.end(); it++) {
		pq.push(it->second.first);
	}

	cout << pq.size() << endl;
	while (!pq.empty()) {
		string name = pq.top();
		pq.pop();
		cout << name << endl;
	}

    return 0;
}
