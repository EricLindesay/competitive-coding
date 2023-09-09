#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;

	while (t--)
	{
		string num;
		cin >> num;
		vector<char> n(num.rbegin(), num.rend()); // reverse the number for easy push_back

		int last_affect = 0;
		for (int i = 0; i < n.size(); ++i)
		{
			if (n[i] >= '5')
			{
				while ((i + 1) < n.size() && n[i + 1] == '9')
				{
					++i;
				}
				if (i + 1 >= n.size())
				{
					n.push_back('1');
					last_affect = n.size() - 1;
				}
				else
				{
					n[i + 1] += 1;
					last_affect = i + 1;
				}
			} 
		}

		// set everything less than last_affect to be zero
		fill(n.begin(), n.begin() + last_affect, '0');

		for (int i = n.size() - 1; i >= 0; --i)
			cout << n[i];
		cout << endl;
	}

	return 0;
}
