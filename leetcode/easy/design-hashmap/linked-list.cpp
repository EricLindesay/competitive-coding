#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class MyHashMap {
private:
	vector<list<pair<int, int>>> values;  // pair of key : value

public:

    MyHashMap() {
        values.resize(1000);
    }

    void put(int key, int value) {
        // see if the key already exists
		list<pair<int, int>> *lst = &values[key%values.size()];

		// Go through this list to find the key
		list<pair<int, int>>::iterator it = lst->begin();
		for (; it != lst->end(); it++) {
			if (it->first == key) {
				// You have found the key, so update it and stop
				// First remove this from the list
				// Then re-add it with the new values
				lst->remove(*it);
				lst->push_back(make_pair(key, value));
				return;
			}
		}

		// It isn't already there, add it to the list
		lst->push_back(make_pair(key, value));
    }
    
    int get(int key) {
		// Get the linked list it should be in
		list<pair<int, int>> *lst = &values[key%values.size()];

		// Go through this list to find the key
		// return it when you find it. Otherwise, just continue
		list<pair<int, int>>::iterator it = lst->begin();
		for (; it != lst->end(); it++) {
			if (it->first == key) {
				return it->second;
			}
		}
		return -1;
    }
    
    void remove(int key) {
        // To remove something, just find the linked list it should be in and remove the element
		list<pair<int, int>> *lst = &values[key%values.size()];

		// Go through this list to find the key
		// when you find it, remove that iterator and stop
		list<pair<int, int>>::iterator it = lst->begin();
		for (; it != lst->end(); it++) {
			if (it->first == key) {
				lst->remove(*it);
				return;
			}
		}
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
