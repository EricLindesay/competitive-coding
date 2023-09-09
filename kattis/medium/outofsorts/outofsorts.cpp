#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool binarySearch(vector<int> &sequence, int target, int low, int high) {
	if (high == low) {
		return false;
	}
	int midpoint = low + (high - low) / 2;
	printf("Sequence midpoint = %d\n", sequence[midpoint]);
	if (target == sequence[midpoint])
		return true;
	else if (target > sequence[midpoint])
		return binarySearch(sequence, target, midpoint+1, high);
	else if (target < sequence[midpoint])
		return binarySearch(sequence, target, low, midpoint);

	return false;
}

void buildSequence(vector<int> &sequence, int m, int a, int c, int x0) {
	int prev = x0;
	for (int &val : sequence) {
		long long intermediate = (a * prev) % m + c % m;
		val = intermediate % m;
		prev = val;
	}
}

void printSequence(vector<int> &sequence) {
	for (int &val: sequence)
		cout << val << " ";
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, a, c, x0;
	cin >> n >> m >> a >> c >> x0;

	vector<int> sequence(n);
	buildSequence(sequence, m, a, c, x0);

	printSequence(sequence);

	int out = 0;
	for (int &val: sequence) {
		printf("Try to find %d in the sequence\n", val);
		// try and find it in the sequence
		if (binarySearch(sequence, val, 0, sequence.size() - 1)) {
			out++;
			printf("FOUND!\n");
		} else {
			printf("NOT FOUND\n");
		}
	}
	cout << out;

    return 0;
}
