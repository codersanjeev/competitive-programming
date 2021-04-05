/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::addTwoNumbers(ListNode *A, ListNode *B) {
	ListNode *dummyHead = new ListNode(0);
	ListNode *C = dummyHead;
	int carry = 0;
	while (A != NULL || B != NULL) {
		int a = A != NULL ? A->val : 0;
		int b = B != NULL ? B->val : 0;
		int curr = a + b + carry;
		ListNode *temp = new ListNode(curr % 10);
		carry = curr / 10;
		C->next = temp;
		C = C->next;
		if (A != NULL) {
			A = A->next;
		}
		if (B != NULL) {
			B = B->next;
		}
	}
	if (carry > 0) {
		ListNode *temp = new ListNode(carry);
		C->next = temp;
	}
	return dummyHead->next;
}
