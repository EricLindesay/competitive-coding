#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void put(list<pair<int, int>> &cards, map<int, int> &freq, int card, int amount, bool top) { 
	if (top) {
		pair<int, int> top = cards.front();
		if (top.first == card) {
			cards.front() = make_pair(top.first, top.second + amount);
		} else {
			cards.push_front(make_pair(card, amount));
		}
	} else {
		pair<int, int> bottom = cards.back();
		if (bottom.first == card) {
			cards.back() = make_pair(bottom.first, bottom.second + amount);
		} else {
			cards.push_back(make_pair(card, amount));
		}
	}

	if (freq.count(card)) {
		freq[card] += amount;
	} else {
		freq[card] = amount;
	}
}

void remove(list<pair<int, int>> &cards, map<int, int> &freq, int amount, bool top) { 
	pair<int, int> c;
	while (amount > 0) {
		if (top) {
			c = cards.front();
			if (c.second > amount) {
				freq[c.first] -= amount;
				cards.front() = make_pair(c.first, c.second - amount);
				amount = 0;
			} else {
				amount -= c.second;
				freq[c.first] -= c.second;
				cards.pop_front();
			}
		} else {
			c = cards.back();
			if (c.second > amount) {
				freq[c.first] -= amount;
				cards.back() = make_pair(c.first, c.second - amount);
				amount = 0;
			} else {
				amount -= c.second;
				freq[c.first] -= c.second;
				cards.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;

	list<pair<int, int>> cards;
	map<int, int> freq;  // card: frequency

	string cmd;
	ll card, amount;
	while (t--) {
		cin >> cmd;
		if (cmd[0] == 'P') {
			cin >> amount >> card;
			// True if its top, false otherwise
			put(cards, freq, card, amount, cmd[4] == 'T');
		} else {
			cin >> amount;
			// True if its top, false otherwise
			remove(cards, freq, amount, cmd[7] == 'T');
		}
		
		//for(pair<int, int> c : cards) {
		//	cout << c.first << ": " << c.second << endl;
		//}
		//cout << endl;
		ll c = INT_MAX;
		ll f = 0;
		for (pair<int, int> p : freq) {
			//cout << p.first << " " << p.second << endl;
			if (p.second > f) {
				c = p.first;
				f = p.second;
			} else if (p.second == f && p.first < c) {
				c = p.first;
				f = p.second;
			}
		}
		cout << c << '\n';
	}

	return 0;
}


