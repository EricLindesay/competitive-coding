#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n, k;
    cin >> n >> k;

	queue<int> processes;  // stores the end time of processes
	double maxConcurrentProcesses = 0;

	while (n--) {
		int request;
		cin >> request;

		// can we remove from the processes?
		while (!processes.empty()) {
			if (request >= processes.front()) {  // the process has completed
				processes.pop();
			} else {
				break;
			}
		}

		// Add the new process in, storing its end time
		processes.push(request + 1000);

		// Is this a new max load?
		maxConcurrentProcesses = max(maxConcurrentProcesses, static_cast<double>(processes.size()));
	}

	cout << ceil(maxConcurrentProcesses/k) << endl;

    return 0;
}
