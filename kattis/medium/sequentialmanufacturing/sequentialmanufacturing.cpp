#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;

	vector<int> t(n);
	vector<int> k(n);

	int totalSum = 0;
	vector<int> cumulativeSum(n, 0);
	int maxT = 0;
	for (int i=0; i<n; i++) {
		cin >> t[i];
		totalSum += t[i];
		maxT = max(maxT, t[i]);
		if (i != 0)
			cumulativeSum[i] = cumulativeSum[i-1] + t[i-1];
	}
	if (n == 1) {
		cout << t[0] * p << endl;
		return 0;
	}

	k[0] = 0;  // the first machine has an input area of 0
	for (int i=1; i<n; i++) {
		cin >> k[i];
	}

	int maxBottleneck = 0; // maximum bottleneck
	int maxBIndex = 0; // index of ^
	int bottleneckSum = 0;
	// find the largest bottleneck
	for (int i=1; i<n; i++) {
		if (t[i] > cumulativeSum[i]) {  // it is a bottleneck if this condition is true
			int diff = t[i] - cumulativeSum[i];
			printf("a bottlneck\n");
			bottleneckSum += diff;
			if (diff > maxBottleneck) {
				bottleneckSum += maxBottleneck;
				maxBottleneck = t[i];
				maxBIndex = i;
				bottleneckSum -= t[i];
			}
		}
	}

	int time = maxT * (p-1) + totalSum; // time assuming you don't have to wait

	int sum = cumulativeSum[maxBIndex];
	printf("maxBottleneck = %d\n", maxBottleneck);
	int diff = maxBottleneck - sum;
	if (diff < 0) { // you don't need to care about how much space you have to wait, it will just process

	} else {
		if (k[maxBIndex] < p)
			time += diff * (p-k[maxBIndex]-2);
	}

	cout << time << endl;

    return 0;
}
