#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class LFUCache {
private:
	int size = 0;
	int capacity = 0;
	map<int, pair<int, int>> cache;  // key : (val, frequency)
	vector<vector<int>> heap;  // [freq, key, val]

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
		heap.resize(capacity, vector<int>(0));
    }

	int parent(int i) {
		return (i - 1)/2;
	}

	int left(int i) {
		return 2*i + 1;
	}

	int right(int i) {
		return 2*i + 2;
	}

	void removeLeastFrequent() {
		if (size <= 0) 
			return;

		if (size == 1) {
			size--;
			heap[0].clear();
			return;
		}

		heap[0] = heap[size - 1];
		size--;

		minHeapify(0);
	}

	void minHeapify(int i) {
		int l = left(i);
		int r = right(i);

		int smallest = i;
		// find the smallest of i, the left node and the right node.
		if (l < size && heap[l][0] < heap[smallest][0])
			smallest = l;
		if (r < size && heap[r][0] < heap[smallest][0])
			smallest = r;

		if (smallest != i) {
			swap(heap[i], heap[smallest]);
			minHeapify(smallest);
		}
	}

	int find(int i, int key) {
		if (i < 0 || i >= size) 
			return -1;

		// dfs
		if (heap[i][1] == key) {
			heap[i][0]++;
			return heap[i][2];
		}

		find(left(i), key);
		find(right(i), key);

		return -1;
	}
    
    int get(int key) {
		return find(0, key); // not found
    }
    
    void put(int key, int value) {
		// if you can already find the key, overwrite the value
        if (size == capacity) {
			removeLeastFrequent();
            return;
        }

        // Inserting the new key at the end
        int i = size;
        heap[size++] = {1, key, value};

        while (i != 0 && heap[parent(i)][0] > heap[i][0]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	LFUCache *lfu = new LFUCache(2);
	lfu->put(1, 1);   // cache=[1,_], cnt(1)=1
	lfu->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
	cout << lfu->get(1) << endl;      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
	lfu->put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
	lfu->get(2);      // return -1 (not found)
	lfu->get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
	lfu->put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
	                 // cache=[4,3], cnt(4)=1, cnt(3)=2
	lfu->get(1);      // return -1 (not found)
	lfu->get(3);      // return 3
			         // cache=[3,4], cnt(4)=1, cnt(3)=3
	lfu->get(4);      // return 4
	                 // cache=[4,3], cnt(4)=2, cnt(3)=3


    return 0;
}
