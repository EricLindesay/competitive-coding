#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <ctime>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, q;
    cin >> n >> q;

	// get and sort the input array (using insertion sort, keeping the list sorted)
	// sort it in ascending order
	clock_t now = clock();

	vector<long long> nums;
	for (int i=0; i<n; i++) {
		long long num;
		cin >> num; 
		// do a linked list insertion-sort on nums. Nums never has to be in order and only exists to be sorted. It is also ever looped through forwards, so a forward_list is best.
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	cout << "\nafter reading first arr " << (clock() - now) << endl;
	
	now = clock();
	// get the next q queries, setting the increment array correctly
	vector<long long> queries(n, 0); // initialise all values to zero.
	for (int i=0; i<q; i++) {
		long long start, end;
		cin >> start >> end;
		start -= 1;
		end -= 1;  // array indexing starts at 1.
		queries[start] += 1;
		if (end+1 < n)
			queries[end+1] -= 1;
	}	
	cout << "initial read of second arr " << (clock()-now) << endl;
	
	now = clock();
	// finish the incrementing to form the difference array.
	for (int i=1; i<n; ++i) {  // this finds all the queries in N time.
							   // doing it manually would be n^2.
							   // this is a difference array
		queries[i] += queries[i-1];
	}

	cout << "before sorting second arr " << (clock() - now) << endl;
	now = clock();
	// sort the queries. This seems to be the most expensive operation here.
	sort(queries.begin(), queries.end());

	cout << "after sorting second arr " << (clock() - now) << endl;
	now = clock();
	// multiply the lowest frequency query by the lowest number, highest by highest, etc
	// can merge this with the one above
	long long ans = 0;
	for (long long i=0; i<n; i++) {
		ans += nums[i] * queries[i];
		i++;
	}
	cout << "after calculating ans " << (clock()-now) << endl;
	
	cout << ans << endl;
    return 0;
}
