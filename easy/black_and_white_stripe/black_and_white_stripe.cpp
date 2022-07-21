#include <iostream>
#include <list>

using namespace std;

void print_ll(list<int> segment) {
	cout << "LL: ";
	for (list<int>::iterator it = segment.begin(); it != segment.end(); it++) {
		int id = *it;
		cout << id << " ";
	}
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;

	while (n-- > 0) {
		long long n, k;
		cin >> n >> k;
	
		bool just_continue = false;
		list<int> segment;
		long long seg_sum = 0;
		long long most_blacks = -1;
		for (long long i=0; i<n; i++) {
			char letter;
			cin >> letter;
			if (just_continue)
				continue;
			int binary;
			binary = (letter == 'B') ? 1 : 0;
			
			seg_sum += binary;
			segment.push_back(binary);
			if (i >= k-1) {
				if (seg_sum == k) {  // theres a solution where we don't have to change anything
					most_blacks = k;
					just_continue = true;
					continue;
				}
				if (seg_sum > most_blacks) {
					most_blacks = seg_sum;
				}
				int first = segment.front();
				segment.pop_front();
				seg_sum -= first;
			}
		}

		cout << k-most_blacks << endl;
		// get each character one by one, black=1, white=0
		// create a vector of size n and put those values in the array.
		// loop through each value in the array and find the sum of i -> i+k
		// then return the minimum value of k-sum
	}

    return 0;
}
