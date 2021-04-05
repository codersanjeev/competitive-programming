#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    int leftCount;
    int count;

    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->leftCount = 0;
        this->count = 0;
    }
};

class Solution {
   public:
    int insert(Node* root, int data) {
        int cnt = 0;
        while (root->data != data) {
            if (root->data > data) {
                if (root->left == nullptr) {
                    root->left = new Node(data);
                }
                root->leftCount++;
                root = root->left;
            } else {
                cnt += root->leftCount + root->count;
                if (root->right == nullptr) {
                    root->right = new Node(data);
                }
                root = root->right;
            }
        }
        root->count++;
        return cnt + root->leftCount;
    }

    vector<int> countSmaller(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N, 0);
        Node* root = new Node(A.back());
        for (int i = N - 1; i >= 0; i--) {
            ans[i] = insert(root, A[i]);
        }
        return ans;
    }
};