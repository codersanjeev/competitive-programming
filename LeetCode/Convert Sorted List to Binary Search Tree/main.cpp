class Solution {
   public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(arr, 0, arr.size() - 1);
    }

   private:
    TreeNode* sortedArrayToBST(const vector<int>& arr, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = sortedArrayToBST(arr, lo, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, hi);
        return root;
    }
};