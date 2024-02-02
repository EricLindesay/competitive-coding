#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;

	map<int, int> cards;
	map<int, int> charges;

	for(int i = 1; i <= m; i++)
	{
		cards[i] = 0;
		charges[i] = 0;
	}

	for(int i = 0; i < k; i++)
	{
		int p, c;
		cin >> p >> c;

		if(cards[c] == 0)
		{
			cards[c] = p;
		}
		else
		{
			if(cards[c] == p)
			{
				charges[c] += 100;
			}
			else
			{
				charges[c] += abs(cards[c] - p);
			}

			cards[c] = 0;
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		if(cards[i] != 0)
		{
			charges[i] += 100;
		}
	}

	for(int i = 1; i<= m; i++)
	{
		cout << charges[i] << " ";
	}
	cout << endl;


    return 0;
}
