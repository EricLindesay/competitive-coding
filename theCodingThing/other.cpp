#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> sqrd(int &n, vector<int> &as) {
	vector<int> output(n);
	for (int i=0; i<as.size(); i++) {
		int other = -1;
		for (int j=i-1; j >= 0; j--) {
			if (as[j] < as[i]) {
				other = j;
			}
		}
		output[i] = other;
	}
	return output;
}

vector<int> nlogn(int &n, vector<int> &as) {
	priority_queue<pair<int, int>> q;
	vector<int> output(n);
	for (int i=0; i<as.size(); i++) {
		q.push(make_pair(as[i], i));
	}
	pair<int, int> a;
	while (!q.empty()) {
		cout << q.top().first << ", " << q.top().second << endl;
		a = q.top();
		q.pop();
		cout << a.second << "x, " << q.top().second << endl;
		output[a.second] = output[q.top().second];
	}
	return output;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;  // 1 -> 10^3
	cin >> n;
	vector<int> as(n);
	for (int &a : as) {
		cin >> a;
	}
	// For each element, output the highest index thats smaller than the current index, if the number is smaller than the current
	// 3, 4, 5, 2, 7
	// Out -> -1, 0, 1, -1, 3
	
	// Could use a priority queue on a pair of first element and index and then just pop from the queue each time - O(nlogn)
	// Could brute force it - O(n^2)
	//
	// can do a stack, put it onto the stack as you see it.
	// Pop from the stack until the top has a valid value, print the index of that value.
	// 3 2 1 4 5 6
	// 3 = [] = -1
	// 2 = [3] = [] = -1
	// 1 = [2] = [] = -1
	// 4 = [1] = 2
	// This is O(n) - It seems like it might be O(n^2) but its actually linear since you only ever put the numbers into the stack once and theres only one comparison
	
	//vector<int> out = sqrd(n, as);
	vector<int> out = nlogn(n, as);
	for (int i : out) {
		cout << i << " ";
	}
	cout << endl;

    return 0;
}
