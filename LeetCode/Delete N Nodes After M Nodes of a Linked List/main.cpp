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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* currentNode = head;
        ListNode* lastNode = head;
        while (currentNode != nullptr) {
            int mCount = m, nCount = n;
            while (currentNode != nullptr && mCount--) {
                lastNode = currentNode;
                currentNode = currentNode->next;
            }
            while (currentNode != nullptr && nCount--) {
                currentNode = currentNode->next;
            }
            lastNode->next = currentNode;
        }
        return head;
    }
};