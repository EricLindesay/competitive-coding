#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <cstring>
#include <algorithm>

typedef long long ll;
using namespace std;

vector<vector<int>> distances;

class Node
{
public:
	int x;
	int y;

	Node(int newX, int newY)
	{
		x = newX;
		y = newY;
	}

	friend bool operator<(const Node &a, const Node &b)
	{
		return distances[a.x][a.y] < distances[b.x][b.y];
	}
};

void print_it(vector<Node> q)
{
	cout << "\nStarting Print\n";
	for (int i = 0; i < q.size(); i++)
	{
		printf("[%d, %d] has dist %d\n", q[i].x, q[i].y, distances[q[i].x][q[i].y]);
	}
	cout << "End print\n";
}

int dijsktra(vector<vector<int>> grid, Node *start, Node *end)
{
	/*
	function dijkstra(G, S)
		for each vertex V in G
			dist[V] <- infinite
			prev[V] <- NULL
			If V != S, add V to Priority Queue Q
		dist[S] <- 0

		while Q IS NOT EMPTY
			U <- Extract MIN from Q
			for each unvisited neighbour V of U
				temperoryDist <- dist[U] + edgeWeight(U, V)
				if temperoryDist < dist[V]
					dist[V] <- temperoryDist
					prev[V] <- U
		return dist[], prev[]
	*/
	vector<vector<pair<int, int>>> prev(grid.size(), (vector<pair<int, int>>(grid[0].size(), {-1, -1})));
	vector<vector<int>> visited(grid.size(), (vector<int>(grid[0].size(), 0)));
	distances.resize(grid.size(), (vector<int>(grid[0].size(), INT_MAX)));

	vector<Node> q;
	// for (int i=0; i<grid.size(); i++) {
	//	for (int j=0; j<grid[0].size(); j++) {
	//		if (grid[i][j] == 0) {
	//			int distance = (i == start->x && j == start->y) ? 0 : INT_MAX;
	//			distances[i][j] = distance;
	//		}
	//	}
	// }
	distances[start->x][start->y] = 0;
	q.push_back(*start);
	// print_it(q);

	while (!q.empty())
	{
		Node ele = q[q.size() - 1];
		q.pop_back();
		int tempDist = distances[ele.x][ele.y] + 1;

		// printf("Consider [%d, %d] with distance %d\n", ele.x, ele.y, distances[ele.x][ele.y]);

		visited[ele.x][ele.y] = 1;
		int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for (int i = 0; i < 4; i++)
		{
			int newX = ele.x + offset[i][0];
			int newY = ele.y + offset[i][1];

			if (newX < 0 || newX >= grid.size())
				continue;
			if (newY < 0 || newY >= grid[0].size())
				continue;
			if (grid[newX][newY] == 1)
				continue; // laser cell

			if (!visited[newX][newY])
			{
				// printf("\tConsider [%d, %d]", newX, newY);
				if (tempDist < distances[newX][newY])
				{
					// printf(" update distance to %d", tempDist);
					memcpy(&distances[newX][newY], &tempDist, sizeof(int));
					prev[newX][newY] = {ele.x, ele.y};
					sort(q.rbegin(), q.rend());
				}
				Node *n = new Node(newX, newY);
				q.push_back(*n);
				// printf("\n");
			}
		}
		// print_it(q);
	}

	//	cout << "Printing distnaces" << endl;
	//	for (int i=0; i<distances.size(); i++) {
	//		for (int j=0; j<distances[0].size(); j++) {
	//			printf("[%d, %d] has distance %d\n", i, j, distances[i][j]);
	//		}
	//	}
	//
	//	cout << "Printing prevs" << endl;
	//	for (int i=0; i<prev.size(); i++) {
	//		for (int j=0; j<prev[0].size(); j++) {
	//			auto[x,y] = prev[i][j];
	//			printf("[%d, %d] has prev [%d, %d]\n", i, j, x, y);
	//		}
	//	}

	if (distances[end->x][end->y] == INT_MAX)
	{
		return -1;
	}
	return distances[end->x][end->y];
}

int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

vector<vector<int>> create_grid(int n, int m, int sx, int sy, int d)
{
	vector<vector<int>> grid(n, vector<int>(m, 0));
	// now update the grid with the deadly cells
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist(i, j, sx, sy) <= d)
			{
				grid[i][j] = 1;
			}
		}
	}
	return grid;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		ll n, m, sx, sy, d; // n rows, m columns, (sx, sy) laser, (d) laser distance
							// robot has to get from (1,1) to (n, m)
		cin >> n >> m >> sx >> sy >> d;
		sx--;
		sy--;
		vector<vector<int>> grid = create_grid(n, m, sx, sy, d);

		if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
		{ // if the start or end is occupied, it must fail
			cout << "-1" << endl;
		}
		else
		{
			Node *start = new Node(0, 0);
			Node *end = new Node(n - 1, m - 1);
			cout << dijsktra(grid, start, end) << endl;
		}
	}
	// diagonals aren't allowed
	return 0;
}
