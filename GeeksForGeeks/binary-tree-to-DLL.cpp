
/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
// Node* head = NULL;
// Node* i = NULL;

void bToDLLutil(Node *root, Node* &head, Node* &i) {
    if (root==NULL) return;
    
    // if not a leaf
    bToDLLutil(root->left, head, i);
    
    if (head==NULL) {
        head = i = root;
    }
    else {
        root->left = i;
        i->right = root;
        i = root;
    }
    
    bToDLLutil(root->right, head, i);
}

Node* bToDLL(Node* root) {
    Node* head = NULL;
    Node* i = NULL;
    bToDLLutil(root, head, i);
    return head;
}