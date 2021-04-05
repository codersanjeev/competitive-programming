/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct comp {
   public:
    bool operator()(ListNode *x, ListNode *y) {
        return x->val > y->val;
    }
};

ListNode *Solution::mergeKLists(vector<ListNode *> &A) {
    priority_queue<ListNode *, vector<ListNode *>, comp> pq;
    for (const auto &ele : A) {
        if (ele != nullptr) {
            pq.push(ele);
        }
    }
    ListNode *dummy = new ListNode(0);
    ListNode *node = dummy;
    while (!pq.empty()) {
        ListNode *curr = pq.top();
        pq.pop();
        node->next = new ListNode(curr->val);
        node = node->next;
        if (curr->next != nullptr) {
            pq.push(curr->next);
        }
    }
    return dummy->next;
}