#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int maxArea(vector<int>& height) {
	int p1=0, p2=height.size()-1;
	
	int m = 0;
	while (p1 < p2) {
		m = max(m, (p2-p1)*min(height[p1],height[p2]));
		if (height[p1] < height[p2]) {
			++p1;
		} else if (height[p1] > height[p2]) {
			--p2;
		} else {
			++p1;
			--p2;
		}
	}
	return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << maxArea(height) << endl;
    return 0;
}
