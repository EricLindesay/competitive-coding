#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<int> numbers(3);
	string order;
	for (int &num : numbers) {
		cin >> num;
	}
	cin >> order;
	sort(numbers.begin(), numbers.end());

	for (char c : order) {
		cout << numbers[c - 'A'] << " ";
	}

    return 0;
}
