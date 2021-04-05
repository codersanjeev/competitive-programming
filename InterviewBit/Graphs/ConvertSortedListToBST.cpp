/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

TreeNode *arrayToBST(vector<int> &arr, int lo, int hi) {
	if (lo > hi) {
		return NULL;
	}
	int mid = lo + (hi - lo) / 2;
	TreeNode *curr = new TreeNode(arr[mid]);
	curr->left = arrayToBST(arr, lo, mid - 1);
	curr->right = arrayToBST(arr, mid + 1, hi);
	return curr;
}

TreeNode *Solution::sortedListToBST(ListNode *head) {
	if (head == NULL) {
		return NULL;
	}
	vector<int> arr;
	while (head != NULL) {
		arr.push_back(head->val);
		head = head->next;
	}
	return arrayToBST(arr, 0, arr.size() - 1);
}
