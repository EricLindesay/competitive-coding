#include <iostream>
#include <forward_list>

using namespace std;

int main() {
	forward_list<int> nums;
	for (int i=0; i<200000; i++) {
		int num = 200000-i;
		forward_list<int>::iterator insert_pos = nums.before_begin();
		for (forward_list<int>::iterator it=nums.begin(); it != nums.end(); ++it) {
			if (*it < num) {
				insert_pos = it;
			} else {
				break;
			}
		} 
		nums.insert_after(insert_pos, num);
	}

	int ans = 0;
	for (forward_list<int>::iterator it=nums.begin(); it != nums.end(); ++it) {
		ans += *it;
	}
}
