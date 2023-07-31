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
	// map containing all the integers we have seen
	map<int, int> seen;

	while (n--) {
		int num;
		cin >> num;
		map<int, int>::iterator it = seen.find(7777-num);
		if (it == seen.end()) {
			// the match isn't there, add the current number so it can be matched
			seen[num] = 1;
		} else {
			// we have already seen the match
			// make sure x != y. This shouldn't be possible but put it in here just in case
			if (num == 7777-num) {
				continue;
			}
			cout << "Yes";
			return;
		}
	}
	cout << "No";
}

void two(ll n) {
	// map containing whether you have seen the number of not
	map<int, int> seen;
	
	while (n--) {
		int num;
		cin >> num;
		if (seen.count(num)) {  // if you have seen the number, there is a duplicate
			cout << "Contains duplicate";
			return;
		}

		// otherwise add this number to the list of seen numbers
		seen[num] = 1;
	}
	
	// No seen numbers were found so it is unique.
	cout << "Unique";
}

void three(ll n) {
	// map containing how many occurrences there have been for each number
	map<int, int> occurrences;
	
	double no2 = n/2.0;
	while (n--) {
		int num;
		cin >> num;
		map<int, int>::iterator it = occurrences.find(num);
		if (it == occurrences.end()) {
			// the match isn't there, add it in
			occurrences[num] = 1;
		} else {
			occurrences[num]++;  // increment the matches. If it is over N/2, print it and stop
			if (occurrences[num] > no2) {
				cout << num;
				return;
			}
		}
	}
	cout << -1;
}

void four(ll n) {
	// Put the numbers into a vector, sort it and print the medians
	vector<int> nums(n);
	for (int &num : nums) 
		cin >> num;

	sort(nums.begin(), nums.end());
	
	if (n%2) {
		cout << nums[n/2];
	} else {
		cout << nums[(n/2)-1] << " " << nums[n/2];
	}
}

void five(ll n) {
	// put the numbers into a vector if they are between 100 and 999
	vector<int> nums;
	while (n--) {
		int num;
		cin >> num;
		if (num >= 100 && num <= 999)
			nums.push_back(num);
	}
	// sort the vector
	sort(nums.begin(), nums.end());

	// print everything in the vector
	for (int num : nums) 
		cout << num << " ";
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
	}

    return 0;
}
