#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class MyHashMap {
private:
	vector<pair<int, int>> tree;  // pair of key : value
	
	int leftChild(int i) {
		return 2*i;
	}

	int rightChild(int i) {
		return 2*i + 1;
	}

	int getIndex(int key) {
		// Returns the index of the key in the tree
		pair<int, int> node = tree[1];
		int i = 1;
		while (node.first != key) {
			if (key < node.first) {
				i = leftChild(i);  // look at the left child
			} else {
				i = rightChild(i);  // look at the right child
			}
			if (!validIndex(i)) {  // if theres a -1, you should stop looking
				// If its out of bounds, return -1
				return -1;
			}
			node = tree[i];
		}
		return i;
	}

	bool validIndex(int i) {
		return (i < tree.size() && tree[i].first != -1);
	}

public:

    MyHashMap() {
		// Initialise the tree with the blank 0'th element
		tree.resize(1, make_pair(-1, -1));
    }

    void put(int key, int value) {
    }
    
    int get(int key) {
		// Try to find it in the key. Compare it to the 0th element
		// then if its less, compare with the left node
		// Otherwise compare with right
		// Go until you can't find the element in the thing. O(logn)

		if (tree.size() <= 1)  // the tree is empty
			return -1;

		int ind = getIndex(key);

		if (ind == -1)
			return -1;
		return tree[ind].second;
    }
    
    void remove(int key) {
		// To remove something, first find the index
		int ind = getIndex(key);

		// Case when it has no children
		if (!validIndex(leftChild(ind)) && !validIndex(rightChild(ind))) {
			// Just remove it
			tree[ind] = make_pair(-1, -1);
		}

		// need to do the two other cases (a left child and right child)
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	MyHashMap *myHashMap = new MyHashMap();
	myHashMap->put(1, 1); // The map is now [[1,1]]
	myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
	cout << myHashMap->get(1) << endl;    // return 1, The map is now [[1,1], [2,2]]
	cout << myHashMap->get(3) << endl;    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
	myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
	cout << myHashMap->get(2) << endl;    // return 1, The map is now [[1,1], [2,1]]
	myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
	cout << myHashMap->get(2) << endl;    // return -1 (i.e., not found), The map is now [[1,

    return 0;
}
