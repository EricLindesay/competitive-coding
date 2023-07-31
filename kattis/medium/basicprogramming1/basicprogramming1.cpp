#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

void one(ll n) {
	cout << 7;
}

void two(ll n) {
	int a, b;
	cin >> a >> b;
	if (a > b) {
		cout << "Bigger";
	} else if (a == b) {
		cout << "Equal";
	} else {
		cout << "Smaller";
	}
}

void three(ll n) {
	vector<int> nums(3);
	for (int i=0; i<3; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());
	cout << nums[1];
}

void four(ll n) {
	ll sum = 0;
	while (n--) {
		int num;
		cin >> num;
		sum += num;
	}
	cout << sum;
}

void five(ll n) {
	ll sum = 0;
	while (n--) {
		int num;
		cin >> num;
		if (num%2 == 0)
			sum += num;
	}
	cout << sum;
}

void six(ll n) {
	int num;
	while (n--) {
		cin >> num;
		printf("%c", 'a' + num%26);
	}
}

void seven(ll n) {
	// read in input
	vector<int> nums(n);
	for (int &num : nums)
		cin >> num;

	// map of whether you have seen this index yet or not
	map<int, bool> seenIndices;

	int i = 0;
	while (true) {
		if (seenIndices.count(i)) {
			// if you've seen the index before, its cyclic
			cout << "Cyclic";
			return;
		}
		if (i >= n || i < 0) {
			cout << "Out";
			return;
		}
		if (i == n-1) {
			cout << "Done";
			return;
		}
		seenIndices[i] = true;

		i = nums[i];
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t;
    cin >> n >> t;

	switch (t) {
		case 1:
			one(n);
			break;
		case 2:
			two(n);
			break;
		case 3:
			three(n);
			break;
		case 4:
			four(n);
			break;
		case 5:
			five(n);
			break;
		case 6:
			six(n);
			break;
		case 7:
			seven(n);
			break;
	}

    return 0;
}
