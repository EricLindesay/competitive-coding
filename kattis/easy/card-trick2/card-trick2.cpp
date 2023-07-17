#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "1" << endl;
			continue;
		}

		vector<int> cards(n, -1);
		cards[1] = 1;

		int i = 1;
		int card = 2;
		// while the distance between the card you should put down is less than the total number of cards
		while (card <= n) {
			int hops = 0;
			while (hops <= card) {
				i = (i + 1) % n;

				// if the index doesn't contain a card which has already been taken
				if (cards[i] == -1) {
					// then don't skip over it
					hops++;
				}
				// otherwise, skip over it
			}

			// place the card in the list of cards
			cards[i] = card;
			card++;
		}

		// print the vector
		for (int card : cards) 
			cout << card << " ";
		cout << endl;
    }

    return 0;
}
