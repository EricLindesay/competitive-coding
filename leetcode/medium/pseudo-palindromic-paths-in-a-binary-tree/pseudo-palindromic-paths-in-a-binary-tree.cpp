#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

typedef long long ll;

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> charCount;

    bool isLeaf(TreeNode *node) {
        return (node->left == nullptr && node->right == nullptr);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ans = 0;
        if (charCount.count(root->val)) {
            charCount[root->val]++;
        } else {
            charCount[root->val] = 1;
        }
        ans += pseudoPalindromicPaths(root->left);
        ans += pseudoPalindromicPaths(root->right);

        if (isLeaf(root)) {
            // Make sure that all the counts are even, except maybe one
            bool oneOff = false;
            for (pair<int, int> c : charCount) {
                if (c.second%2 != 0) {
                    if (oneOff) {
                        // not a solution
                        charCount[root->val]--;
                        return 0;
                    } else {
                        oneOff = true;
                    }
                }
            }
			// is a solution
            charCount[root->val]--;
            return 1;
        }

        charCount[root->val]--;
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cout << Solution(). << endl;

    return 0;
}
