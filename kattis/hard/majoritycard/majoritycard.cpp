#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void remove(map<int, bool> &v, int &val) {
	v.erase(val);
}

void remove_amount(map<int, map<int, bool>, greater<int>> &freq, map<int, int> &amounts, int card, int amount) {
	remove(freq[amounts[card]], card);
	if (freq[amounts[card]].size() == 0) {
		freq.erase(amounts[card]);
	}
	amounts[card] -= amount;
					
	// add to new frequency
	freq[amounts[card]][card] = true;
}

void add_amount(map<int, map<int, bool>, greater<int>> &freq, map<int, int> &amounts, int card, int amount) {
	if (amounts.count(card)) {
		// its already there
		// remove it from it's previous frequency and add it to the new one
		remove(freq[amounts[card]], card);
		if (freq[amounts[card]].empty()) {
			freq.erase(amounts[card]);
		}
		amounts[card] += amount;
				
		//cout << "For freq: " << amounts[card] << "| ";
		//for (int c : freq[amounts[card]]) {
		//	cout << c << " " ;
		//}
		//cout << endl;

		freq[amounts[card]][card] = true;
	} else {
		amounts[card] = amount;
		freq[amounts[card]][card] = true;
		//cout << "Create new " << card << endl;
	}
}

void print_freq(map<int, map<int, bool>, greater<int>> &freq) {
	for (pair<int, map<int, bool>> card: freq) {
		cout << card.first << "|";
		for (pair<int, bool> c: card.second) {
			cout << c.first << " ";
		}
	}
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	list<pair<int, int>> cards;  // card type, card amount
	map<int, int> amounts;  // <card, freq>
	map<int, map<int, bool>, greater<int>> freq;  // freq: <card, true>
											   // could have a hashmap for constant lookup here but then finding best is harder. Actually it isn't since the inner map will be sorted anyway and the outer keeps the sorting
											   // or a separate hashmap of value -> index
	map<int, int> indexLookup;  // but if you remove something, this gets bad

	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "PUT_TOP") {
			int amount, card;
			cin >> amount >> card;
			if (cards.front().first == card) {  // merge this with the previous of the same type
				pair<int, int> f = cards.front();
				cards.pop_front();
				cards.push_front({card, amount + f.second});
			} else {
				cards.push_front({card, amount});
			}
			// instead of putting on that many cards, instead put on a pair of card to amount
			// then when you remove, you can just remove up to the amount. Much quicker remove for adjacent elements
			add_amount(freq, amounts, card, amount);
		} else if (cmd == "PUT_BOTTOM") {
			int amount, card;
			cin >> amount >> card;
			if (cards.back().first == card) {  // merge this with the previous of the same type
				pair<int, int> f = cards.back();
				cards.pop_back();
				cards.push_back({card, amount + f.second});
			} else {
				cards.push_back({card, amount});
			}
			add_amount(freq, amounts, card, amount);
		} else if (cmd == "REMOVE_TOP") {
			int amount;
			cin >> amount;
			while (amount > 0) {
				pair<int, int> f = cards.front();
				cards.pop_front();
				int card = f.first;
				if (amount >= f.second) {
					// remove everything from this pair
					amount -= f.second;
					remove_amount(freq, amounts, card, f.second);
				} else {
					// only remove what is remaining
					cards.push_front({card, f.second - amount});
					remove_amount(freq, amounts, card, amount);
					amount = 0;
				}
			}
		} else if (cmd == "REMOVE_BOTTOM") {
			int amount;
			cin >> amount;
			while (amount > 0) {
				pair<int, int> f = cards.back();
				cards.pop_back();
				int card = f.first;
				if (amount >= f.second) {
					// remove everything from this pair
					amount -= f.second;
					remove_amount(freq, amounts, card, f.second);
				} else {
					// only remove what is remaining
					cards.push_back({card, f.second - amount});
					remove_amount(freq, amounts, card, amount);
					amount = 0;
				}
			}
		}

		//for (pair<int, int> card : cards) {
		//	cout << card.first << "|" << card.second << " ";
		//}
		//cout << endl;
	//	print_freq(freq);
		//for (pair<int, vector<int>> card: freq) {
		//	cout << card.first << "|";
		//	for (int c: card.second) {
		//		cout << c << " ";
		//	}
	//	}
		//cout << endl;
		// print the card with the highest amount
		for (pair<int, map<int, bool>> cards: freq) {
			for (pair<int, bool> card : cards.second) {
				cout << card.first << endl;
				break;  // we only want to print the highest
			}
			break;
		}
	}

    return 0;
}
