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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);
        ListNode* ans = addTwoNumbersUtility(l1, l2);
        ans = reverseLinkedList(ans);
        return ans;
    }

   private:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* addTwoNumbersUtility(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        int remainder = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int curr = l1->val + l2->val + remainder;
            ans->next = new ListNode(curr % 10);
            ans = ans->next;
            remainder = curr / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            int curr = l1->val + remainder;
            ans->next = new ListNode(curr % 10);
            ans = ans->next;
            remainder = curr / 10;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int curr = l2->val + remainder;
            ans->next = new ListNode(curr % 10);
            ans = ans->next;
            remainder = curr / 10;
            l2 = l2->next;
        }
        if (remainder > 0) {
            ans->next = new ListNode(remainder);
        }
        return dummy->next;
    }
};