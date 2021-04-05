/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int findLength(ListNode *head) {
	int ans = 0;
	while (head != NULL) {
		ans++;
		head = head->next;
	}
	return ans;
}

ListNode *Solution::rotateRight(ListNode *head, int k) {
	int len = findLength(head);
	k %= len;
	if (k == 0 || head == NULL || head->next == NULL) {
		return head;
	}
	ListNode *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	head = head->next;
	temp = temp->next;
	for (int i = 1; i < len - k; i++) {
		head = head->next;
		temp = temp->next;
	}
	temp->next = NULL;
	return head;
}
