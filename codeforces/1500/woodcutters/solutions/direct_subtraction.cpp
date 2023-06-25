#include <iostream>
#include <vector>

using namespace std;

int main() {
    // read input
    int n;
    scanf("%d", &n);
    vector<vector<int>> arr = {};
    
    int i = 0;
    while (i++ < n) {
    	int n1, n2;
	    scanf("%d %d", &n1, &n2);
	    vector<int> temp = {n1, n2};
	    arr.push_back(temp);
    }

    int trees_felled = 1;  // only include the last tree
    int available_space = 0;
    if (n > 1) {
        available_space = arr[1][0] - arr[0][0];
        trees_felled++;
    }

    for (int i=1; i < n-1; i++) {
        int distance = arr[i+1][0]-arr[i][0];
        if (available_space > arr[i][1]) {
            // either its first tree or there's enough space
            // fell to the left
            trees_felled++;
            available_space = distance;
        } else {
            // can we fell to the right?
            if (distance > arr[i][1]) {
                trees_felled++;
                available_space = distance - arr[i][1];
            } else {
                available_space = distance;
            }
        }
    }

    printf("%d", trees_felled);
    return 0;
}

