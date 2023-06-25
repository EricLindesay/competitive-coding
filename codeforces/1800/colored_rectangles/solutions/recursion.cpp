#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;

int recursion(int, int, int);

vector<int> reds, greens, blues;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int r, g, b;
	string sizes;
	getline(cin, sizes);
	sscanf(sizes.c_str(), "%d %d %d", &r, &g, &b);

//	vector<int> reds;
//	vector<int> greens;
//	vector<int> blues;

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

	sort(reds.begin(), reds.end());
	sort(greens.begin(), greens.end());
	sort(blues.begin(), blues.end());

	int score = recursion(r-1, g-1, b-1);

	printf("%d", score);
	return 0;
}

int recursion(int r, int g, int b) {
	int s1=0, s2=0, s3=0;

	if (r >= 0 && g >= 0) 
		s1 = reds[r]*greens[g] + recursion(r-1, g-1, b);
	if (r >= 0 && b >= 0) 
		s2 = reds[r]*blues[b] + recursion(r-1, g, b-1);
	if (g >= 0 && b >= 0) 
		s3 = greens[g]*blues[b] + recursion(r, g-1, b-1);

	return max({s1, s2, s3});
}


