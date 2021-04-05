/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::deleteDuplicates(ListNode *A) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = A;
	ListNode *temp = dummy;
	while (temp->next != NULL) {
		ListNode *temp2 = temp->next;
		while (temp2->next != NULL && temp2->val == temp2->next->val) {
			temp2 = temp2->next;
		}
		if (temp->next != temp2) {
			temp->next = temp2->next;
		} else {
			temp = temp2;
		}
	}
	return dummy->next;
}
