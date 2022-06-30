#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, q;
    cin >> n >> q;

	forward_list<long long> nums;
	for (int i=0; i<n; i++) {
		long long num;
		cin >> num; 
		// do a linked list insertion-sort on nums. Nums never has to be in order and only exists to be sorted. It is also ever looped through forwards, so a forward_list is best.
		forward_list<long long>::iterator insert_pos = nums.before_begin();
		for (forward_list<long long>::iterator it=nums.begin(); it != nums.end(); ++it) {
			if (*it < num) {
				insert_pos = it;
			} else {
				break;
			}
		} 
		nums.insert_after(insert_pos, num);
	}

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
	
	for (int i=1; i<n; ++i) {  // this finds all the queries in N time.
							   // doing it manually would be n^2.
							   // this is a difference array
		queries[i] += queries[i-1];
	}

	sort(queries.begin(), queries.end());

	long long ans = 0;
	long long i = 0;
	for (forward_list<long long>::iterator it=nums.begin(); it != nums.end(); ++it) {
		ans += *it * queries[i];
		i++;
	}	
	
	cout << ans;
    return 0;
}
