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
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *current = head;
		while (current != nullptr && current->next != nullptr) {
			if (current->next->val == current->val) {
				current->next = current->next->next;
			} else {
				current = current->next;
			}
		}
		return head;
	}
};