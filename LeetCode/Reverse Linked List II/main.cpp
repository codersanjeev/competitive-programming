class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int k = 1;
        while (k < m) {
            prev = curr;
            curr = curr->next;
            k++;
        }
        ListNode* joinOne = prev;
        ListNode* joinTwo = curr;
        while (k <= n) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k++;
        }
        if (joinOne != nullptr) {
            joinOne->next = prev;
        } else {
            head = prev;
        }
        joinTwo->next = curr;
        return head;
    }
};