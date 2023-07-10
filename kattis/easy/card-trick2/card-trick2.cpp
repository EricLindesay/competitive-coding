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

    for (int i = 0; i < t; i++)
    {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "1" << endl;
			continue;
		}

		vector<int> cards(n, -1);
		vector<bool> seen(n, 0);
		cards[1] = 0;  // the second card is always a 1.
		seen[0] = true;
		int numSeen = 1;

		int cardIndex = 1;  // you start at index 1
		int nextCardInc = 2;
		while (numSeen < n) {
			// now we have removed 4
			// next card inc is how many cards to see then we accept the third card
			int i=cards[cardIndex];
			while (nextCardInc > 0) {
				if (!cards[i]) {
					nextCardInc--;
				}
				i = (i + 1) % n;
			}
			cardIndex = (cardIndex + 1) % n;
			cards[cardIndex] = i;
			seen[i] = true;
			numSeen++;
			nextCardInc++;
		}

		// print the loop
		for (int i=0; i<cards.size(); i++) {
			cout << cards[i] + 1 << " ";
		}
		cout << endl;
    }

    return 0;
}
