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

bool same_sizes(int r, int g, int b) {
	return (r == g && g == b);
}

bool values_equal(int r, int g, int b) {
	return (reds[r] == greens[g] && greens[g] == blues[b]);
}

int recursion(int r, int g, int b) {
	int s1=0, s2=0, s3=0;
	int red = reds[r];
	int green = greens[g];
	int blue = blues[b];

	if (same_sizes(r, g, b) && !values_equal(r, g, b)) {
		printf("test");
		// if two of the values are equal to the min. Then we need to do two scenarios, one for each.
		// otherwise, just find highest two and do the recursion on those two.
		if (red > green && green == blue) {
			s1 = red*green + recursion(r-1, g-1, b);
			s2 = red*blue + recursion(r-1, g, b-1);
			return max(s1, s2);
		}
		if (green > red && red == blue) {
			s1 = green*red + recursion(r-1, g-1, b);
			s2 = green*blue + recursion(r, g-1, b-1);
			return max(s1, s2);
		}

		if (blue > red && red == green) {
			s1 = blue*red + recursion(r-1, g, b-1);
			s2 = blue*green + recursion(r, g-1, b-1);
			return max(s1, s2);
		}
		// do the situation where there is only one recursion.
//		take the best two and just do the recursion on that.
		if (red < green && red < blue) {
			// green and blue are the hoghest two
			return green*blue + recursion(r, g-1, b-1);
		}
		if (green < red && green < blue) {
			// red and blue are the highest two
			return red*blue + recursion(r-1, g, b-1);
		}
		if (blue < red && blue < green) {
			// red and green are the highest two
			return red*green + recursion(r-1, g-1, b);
		}
	}
	

	if (r >= 0 && g >= 0) 
		s1 = red*green + recursion(r-1, g-1, b);
	if (r >= 0 && b >= 0) 
		s2 = red*blue + recursion(r-1, g, b-1);
	if (g >= 0 && b >= 0) 
		s3 = green*blue + recursion(r, g-1, b-1);


	// do remaining if there are some

	return max({s1, s2, s3});
}


