#include <iostream>
#include <vector>

using namespace std;

int main() {
    // read input
    int n;
    scanf("%d", &n);
    vector<vector<int>> arr = {};
    
    while (n-- > 0) {
    	int n1, n2;
	    scanf("%d %d", &n1, &n2);
	    vector<int> temp = {n1, n2};
	    arr.push_back(temp);
    }
    
    // array of 0s and 1s which is as long as the furthest position
    // initialise all the stump positions as 1
    // ignore the first and last tree. These will always be able to be cut down.
    // prioritise felling to the left.
    // if you do drop to the left, we can don't have to update positions

    // everytime you see a zero, add to a counter saying available length
    int highest_dist = arr[arr.size()-1][0] - 2;
    int *positions = (int *) calloc(highest_dist, sizeof(int));  // -2 because we don't care about the first or last tree. They will always be cut down.

    for (int i=1; i<arr.size()-1; i++) {
        positions[arr[i][0]-2] = arr[i][1];
    }
    /*
    positions
    -1 = a felled tree
    0 = an empty spot
    >0 = the height of the tree
    */
    int trees_felled = 2;
    int check_right = 0;

    int count = 0;
    for (int i=0; i<highest_dist; i++) {      
        if (positions[i] > 0) {  // it's a stump
            check_right = 0;  // stop checking right
            if (count >= positions[i]) {
                // fell to the left
                trees_felled++;
            } else {
                // see if you can fell to the right
                check_right = positions[i];
            }
            count = 0;
        } else if (positions[i] == 0) {
            count++;
            if (check_right != 0 && count == check_right) {
                // you can fell the tree to the right
                count = 0;
                trees_felled++;
                check_right = 0;
            }
        }
    }

    printf("%d", trees_felled);
    free(positions);
    return 0;
}

