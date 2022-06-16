#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>

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

	int *length = (int *) calloc(n, sizeof(int));
	int *total = (int *) calloc(n, sizeof(int));
	int *best_num = (int *) calloc(n, sizeof(int));
	int *pos = (int *) calloc(n, sizeof(int));
	int *highest_score = (int *) calloc(n, sizeof(int));
	int *score = (int *) calloc(n, sizeof(int));

	for (int i=0; i<n; i++) {  // start position

	}	
	//int highest = max(highest_score);
	int highest = 0;
	printf("%d", highest);
	
	return 0;
}





