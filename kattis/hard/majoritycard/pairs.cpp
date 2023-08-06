#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void remove(vector<int> &v, int &val) {
	auto it = v.begin();
	while (it != v.end()) {
		if ((*it) == val) {
			v.erase(it);
			return;
		}
		++it;
	}
}

void remove_amount(map<int, vector<int>, greater<int>> &freq, map<int, int> &amounts, int card, int amount) {
	remove(freq[amounts[card]], card);
	if (freq[amounts[card]].size() == 0) {
		freq.erase(amounts[card]);
	}
	amounts[card] -= amount;
					
	// add to new frequency
	freq[amounts[card]].push_back(card);
}

void print_freq(map<int, vector<int>, greater<int>> &freq) {
	for (pair<int, vector<int>> card: freq) {
		cout << card.first << "|";
		for (int c: card.second) {
			cout << c << " ";
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
	map<int, vector<int>, greater<int>> freq;  // freq: cards

	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "PUT_TOP") {
			int amount, card;
			cin >> amount >> card;
			cards.push_front({card, amount});
			// instead of putting on that many cards, instead put on a pair of card to amount
			// then when you remove, you can just remove up to the amount. Much quicker remove for adjacent elements
			if (amounts.count(card)) {
				// its already there
				// remove it from it's previous frequency and add it to the new one
				remove(freq[amounts[card]], card);
				if (freq[amounts[card]].size() == 0) {
					freq.erase(amounts[card]);
				}
				amounts[card] += amount;
				
				//cout << "For freq: " << amounts[card] << "| ";
				//for (int c : freq[amounts[card]]) {
				//	cout << c << " " ;
				//}
				//cout << endl;

				if (find(freq[amounts[card]].begin(), freq[amounts[card]].end(), card) == freq[amounts[card]].end()) {  // if it isn't already there, add it
				//																										cout << "Not there yet" << endl;
					freq[amounts[card]].push_back(card);
				}
			} else {
				amounts[card] = amount;
				freq[amounts[card]].push_back(card);
				//cout << "Create new " << card << endl;
			}
		} else if (cmd == "PUT_BOTTOM") {
			int amount, card;
			cin >> amount >> card;
			cards.push_back({card, amount});
			if (amounts.count(card)) {
				remove(freq[amounts[card]], card);
				if (freq[amounts[card]].size() == 0) {
					freq.erase(amounts[card]);
				}
				amounts[card] += amount;
				//cout << "For freq: " << amounts[card] << "| ";
				//for (int c : freq[amounts[card]]) {
				//	cout << c << " " ;
				//}
				//cout << endl;
				if (find(freq[amounts[card]].begin(), freq[amounts[card]].end(), card) == freq[amounts[card]].end()) {  // if it isn't already there, add it
				//																										cout << "Not there yet" << endl;
					freq[amounts[card]].push_back(card);
				}
			} else {
				amounts[card] = amount;
				freq[amounts[card]].push_back(card);
				//cout << "Create new " << card << endl;
			}
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
					cards.push_front({card, f.second - amount});
					remove_amount(freq, amounts, card, amount);
					amount = 0;
				}
			}
		}

		//for (pair<int, vector<int>> card: freq) {
		//	cout << card.first << "|";
		//	for (int c: card.second) {
		//		cout << c << " ";
		//	}
	//	}
		//cout << endl;
		// print the card with the highest amount
		for (pair<int, vector<int>> card: freq) {
			sort(card.second.begin(), card.second.end());
			cout << card.second[0] << endl;
			break;
		}
	}

    return 0;
}
