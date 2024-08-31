#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> employees;  // List containing employees[x] index in the tree
vector<int> t;  // BTree containing salaries

void insert(int employee, int salary) {
	int v = 0;
	while (t[v] != -1) {  // there is already something in there

	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	employees = vector<int>(n);
	for (int &i : employees) {
		cin >> i;
	}

	int nodes = pow(2, ceil(log2(n)));

	t = vector<int>(nodes, -1);
	// insert each employee into the tree, keeping track of the index they land in

    return 0;
}
