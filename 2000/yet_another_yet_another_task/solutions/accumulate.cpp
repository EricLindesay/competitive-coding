#include <iostream>
#include <vector> 
#include <string>

using namespace std;


vector<string> split(string, string);

vector<int> read_nums() {
    vector<int> nums;
    string s;
    getline(cin, s);
    vector<string> tokens = split(s, " ");
    for (string token : tokens) {
		int val;
		sscanf(token.c_str(), "%d", &val);
		nums.push_back(val);
    }
    return nums;
}

vector<string> split(string s, string delim) {
    size_t pos = 0;
    string token;
    vector<string> tokens;
    while ((pos = s.find(delim)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delim.length());
    }
    tokens.push_back(s);  // add what is left of s
    return tokens;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	getline(cin, s);
	sscanf(s.c_str(), "%d", &n);
	vector<int> nums = read_nums();	

	int highest = 0;
	for (int i=0; i<n; i++) {  // start position
		int seg_sum = 0;
		int seg_highest = 0;
		if (nums[i] < 0) {  // you will never want to start on a negative number
			continue;
		}
		for (int j=i; j<n; j++) {  // end position of segment
			if (nums[j] > seg_highest) {  // the highest value is going to be removed by Bob
				seg_sum += seg_highest;
				seg_highest = nums[j];
			} else {
				seg_sum += nums[j];
			}	
	
			if (nums[j] <= 0) {  // you will never want to end on a negative number
				continue;
			}
			if (seg_sum <= 0 && i != j) {  // if the sum is ever <= 0, we don't want to consider the rest of that segment (as long as its not just a one segment long thing).
				break;
			}
			if (seg_sum > highest) {
				highest = seg_sum;
			}
		}
	}	
	printf("%d", highest);
	
	return 0;
}





