#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <numeric>

using namespace std;

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

vector<int> read_nums(int n) {
    vector<int> nums;
    string s;
    getline(cin, s);
    vector<string> tokens = split(s, " ");
    for (string token : tokens) {
        nums.push_back(stoi(token));
    }
    return nums;
}

vector<int> first_x(vector<int> items, int x, bool reverse) {
    vector<int> n;
    int i = 0;
    while (i < x) {
        if (reverse) {
            n.push_back(items[items.size()-i-1]);
            i++;
        } else {
            n.push_back(items[i++]);
        }
    }
    return n;
}

int main() {
	int n_items, cases;
	string line;
    getline(cin, line);
    sscanf(line.c_str(), "%d %d", &n_items, &cases);

	vector<int> items = read_nums(n_items);
    sort(items.rbegin(), items.rend());

	while (cases-- > 0) {
        int x,y;
        scanf("%d %d", &x, &y);
        vector<int> subitems = first_x(items, x, false);
        
        vector<int> cheapest = first_x(subitems, y, true);
        
        int sum = 0;
        for (int c : cheapest) {
            sum += c;
        }
        printf("%d\n", sum);
	}
	return 0;
}
