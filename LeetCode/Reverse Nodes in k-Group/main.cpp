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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }
        ListNode* dummy = new ListNode();
        ListNode* start = dummy;
        dummy->next = head;
        int cnt = 0;
        while (head != nullptr) {
            cnt++;
            if (cnt % k == 0) {
                start = reverseLinkedList(start, head->next);
                head = start->next;
            } else {
                head = head->next;
            }
        }
        return dummy->next;
    }

   private:
    ListNode* reverseLinkedList(ListNode* start, ListNode* end) {
        ListNode* prev = start;
        ListNode* curr = start->next;
        ListNode* first = curr;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        start->next = prev;
        first->next = curr;
        return first;
    }
};