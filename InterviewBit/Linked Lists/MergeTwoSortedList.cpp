/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::mergeTwoLists(ListNode *A, ListNode *B) {
	if (A == NULL && B == NULL) {
		return NULL;
	}
	if (A == NULL) {
		return B;
	}
	if (B == NULL) {
		return A;
	}
	ListNode *ans;
	if (A->val < B->val) {
		ans = A;
		ans->next = mergeTwoLists(A->next, B);
	} else {
		ans = B;
		ans->next = mergeTwoLists(A, B->next);
	}
	return ans;
}
