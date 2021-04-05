/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode *A) {
	stack<int> st;
	ListNode *temp = A;
	while (temp != NULL) {
		st.push(temp->val);
		temp = temp->next;
	}
	while (A != NULL) {
		if (st.top() != A->val) {
			return 0;
		}
		st.pop();
		A = A->next;
	}
	return 1;
}
