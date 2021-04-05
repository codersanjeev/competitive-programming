/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

	TreeNode* ans = NULL;

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ans = NULL;
        search(original, cloned, target);
        return ans;
    }

    void search(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    	if (original == NULL) {
    		return;
    	}
    	if (original == target) {
    		ans = cloned;
    		return;
    	}
    	search(original->left, cloned->left, target);
    	search(original->right, cloned->right, target);
    }

};