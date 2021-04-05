#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int data;
    int leftCount;
    int count;

    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->leftCount = 0;
        this->count = 0;
    }
};

int insert(TreeNode *root, int data) {
    int cnt = 0;
    while (root->data != data) {
        if (root->data > data) {
            if (root->left == nullptr) {
                root->left = new TreeNode(data);
            }
            root->leftCount++;
            root = root->left;
        } else {
            cnt += root->leftCount + root->count;
            if (root->right == nullptr) {
                root->right = new TreeNode(data);
            }
            root = root->right;
        }
    }
    root->count++;
    return cnt + root->leftCount;
}

vector<int> solve(const vector<int> &A) {
    int N = A.size();
    vector<int> ans(N, 0);
    TreeNode *root = new TreeNode(A.back());
    for (int i = N - 1; i >= 0; i--) {
        ans[i] = insert(root, A[i]);
    }
    return ans;
}