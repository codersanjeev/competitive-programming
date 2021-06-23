class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *previousNode = dummyNode, *currentNode = dummyNode->next;
        for (int i = 1; i < left; ++i) {
            currentNode = currentNode->next;
            previousNode = previousNode->next;
        }
        for (int i = 0; i < right - left; ++i) {
            ListNode* temporaryNode = currentNode->next;
            currentNode->next = temporaryNode->next;
            temporaryNode->next = previousNode->next;
            previousNode->next = temporaryNode;
        }
        return dummyNode->next;
    }
};