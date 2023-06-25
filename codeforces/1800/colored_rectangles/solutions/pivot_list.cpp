#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;

int using_pivot(int, int, int, vector<int>, vector<int>, vector<int>);
int custom_sum(int, int, vector<int>, vector<int>);
int get_best_list(int, int, vector<int>, vector<int>);

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

	sort(reds.rbegin(), reds.rend());
	sort(greens.rbegin(), greens.rend());
	sort(blues.rbegin(), blues.rend());

	printf("\n");
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

	int score1 = using_pivot(r, g, b, reds, greens, blues);
	printf("\n");
	int score2 = using_pivot(g, r, b, greens, reds, blues);
	int score3 = using_pivot(b, r, g, blues, reds, greens);

	printf("%d", max({score1, score2, score3}));
	return 0;
}

int using_pivot(int a, int b, int c, vector<int> arr1, vector<int> arr2, vector<int> arr3) {
	int sum=0;
	while (a > 0 && b > 0 && c > 0) {
		// make sure to decrement abc as required.
		int num1 = arr1[0];
		int num2 = arr2[0];
		int num3 = arr3[0];
		int max_num = max(num2, num3);
		int to_choose = get_best_list(b, c, arr2, arr3);
		// if they are equal, choose the one with the shortest array length
		if (to_choose == 0) {
			b--;
			arr2.erase(arr2.begin());
			printf("\nremove from B");
		} else {
			c--;
			arr3.erase(arr3.begin());
			printf("\nremove from C");
		}
		a--;
		arr1.erase(arr1.begin());
		sum += num1*max_num;
	}	
	
	if (a > 0 && b > 0) {
		// use up the remainders of b
		sum += custom_sum(a, b, arr1, arr2);
	} else if (a > 0 && c > 0) {
		// use up the remainders of c
		sum += custom_sum(a, c, arr1, arr3);
	}

	if (b > 0 && c > 0) {
		// work out the maximum from those two arrays
		sum += custom_sum(b, c, arr2, arr3);
	}

	return sum;
}

int custom_sum(int a, int b, vector<int> arr1, vector<int> arr2) {
	int sum=0;
	for (int i=0; i<min(a, b); i++) {
		sum += arr1[i]*arr2[i];
	}

	return sum;
}

int get_best_list(int b, int c, vector<int> arr2, vector<int> arr3) {
	if (arr2[0] > arr3[0])
		return 0;
	else if (arr2[0] < arr3[0])
		return 1;
	else {
		if (b > c)
			return 0;
		else
			return 1;
	}	
}

