#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int r, g, b;
	string sizes;
	getline(cin, sizes);
	sscanf(sizes.c_str(), "%d %d %d", &r, &g, &b);

	vector<int> reds;
	vector<int> greens;
	vector<int> blues;

	string s;
	getline(cin, s);
    istringstream sstr(s);	
	int num;
	while (sstr >> num) {
		reds.push_back(num);
	}

	getline(cin, s);
    istringstream s2str(s);	
	while (s2str >> num) {
		greens.push_back(num);
	}
	
	getline(cin, s);
    istringstream s3str(s);	
	while (s3str >> num) {
		blues.push_back(num);
	}

	for (int i: reds) {
		cout << i << ", ";
	}
	cout << endl;
	for (int i: greens) {
		cout << i << ", ";
	}
	cout << endl;
	for (int i: blues) {
		cout << i << ", ";
	}
	cout << endl;

	return 0;
}



