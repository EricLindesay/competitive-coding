#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int listsSize = lists.size();
        vector<int> indices(lists.size(), 0);
		ListNode *out = new ListNode();
		ListNode *head = out;
		
		while (listsSize > 0) {
			ListNode *smallestNode = nullptr;
			for (ListNode *lst : lists) {
				if (smallestNode == nullptr || lst->val < smallestNode->val) {
					smallestNode = lst;
				}
			}
			out->val = smallestNode->val;
			out->next = new ListNode();
			smallestNode = smallestNode->next;
			if (smallestNode == nullptr) {
				listsSize--;
			}	
		}
		return head;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
