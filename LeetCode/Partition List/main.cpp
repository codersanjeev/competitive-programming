/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode *l = &left, *r = &right;
        while (head != nullptr) {
            ListNode*& node = head->val < x ? l : r;
            node->next = head;
            node = node->next;
            head = head->next;
        }
        l->next = right.next;
        r->next = nullptr;
        return left.next;
    }
};