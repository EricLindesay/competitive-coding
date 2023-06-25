#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int maxArea(vector<int>& height) {
	// go through forwards.
	// Then for each forward one, loop backwards until you find one >= to it.
	// If there isn't one >= to it (so far) continue looping but store the value as the current
	// max. If you find a new one which is larger then overwrite the max.
	// thats slow O(n^2)

	int m = 0;
	for (int i=0; i<height.size(); i++) {
		int p = height.size() - 1;
		while (p > i) {
			int minHeight = min(height[i], height[p]);
			m = max(m, minHeight*(p-i));
			if (height[p] >= height[i]) {
				// you know this will be the max area (or its already been found)
				// going any further in won't help you
				break;
			}
			--p;
		}
	}
	return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<int> heights = {1, 8,6,2,5,4,8,3,7};
	cout << maxArea(heights) << endl;

    return 0;
}
