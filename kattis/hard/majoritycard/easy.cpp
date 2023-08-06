#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	list<int> cards;
	map<int, int> amounts;  // <card, freq>

	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "PUT_TOP") {
			int amount, card;
			cin >> amount >> card;
			cards.insert(cards.begin(), amount, card);
			if (amounts.count(card)) {
				// its already there
				amounts[card] += amount;
			} else {
				amounts[card] = amount;
			}
		} else if (cmd == "PUT_BOTTOM") {
			int amount, card;
			cin >> amount >> card;
			cards.insert(cards.end(), amount, card);
			if (amounts.count(card)) {
				amounts[card] += amount;
			} else {
				amounts[card] = amount;
			}
		} else if (cmd == "REMOVE_TOP") {
			int amount;
			cin >> amount;
			for (int i=0; i<amount; i++) {
				int card = cards.front();
				cards.pop_front();
				amounts[card]--;
				if (amounts[card] == 0) {
					amounts.erase(card);
				}
			}
		} else if (cmd == "REMOVE_BOTTOM") {
			int amount;
			cin >> amount;
			for (int i=0; i<amount; i++) {
				int card = cards.back();
				cards.pop_back();
				amounts[card]--;
				// if there are none left, delete it
				if (amounts[card] == 0) {
					amounts.erase(card);
				}
			}
		}

		// find the card with the highest amount
		int bestCard = 0;
		int bestFrequency = -1;
		for (pair<int, int> card: amounts) {
			if (card.second > bestFrequency) {
				bestCard = card.first;
				bestFrequency = card.second;
			} else if (card.second == bestFrequency) {
				if (card.first < bestCard) {
					bestCard = card.first;
					bestFrequency = card.second;
				}
			}
		}
		cout << bestCard << endl;
	}

    return 0;
}
