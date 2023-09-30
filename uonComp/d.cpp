#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Node
{
public:
	int connection;
	int max;
	int current;

	Node(int d, int c, int u)
	{
		connection = d;
		max = c;
		current = u;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, w;
	cin >> n >> w;
	vector<Node> nodes(n);

	int i = 1;
	nodes[0] = Node(0, 75, 0);
	while (n--)
	{
		int d, c, u;
		cin >> d >> c >> u;
		nodes[i] = Node(d, c, u);
		i++;
	}

	return 0;
}
