/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::detectCycle(ListNode *head) {
	ListNode *slow = head;
	ListNode *fast = head;
	while (slow != NULL && fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			ListNode *temp = head;
			while (temp != slow) {
				slow = slow->next;
				temp = temp->next;
			}
			return temp;
		}
	}
	return NULL;
}
