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
	ListNode *swapPairs(ListNode *head) {
		ListNode *dummy = head;
		while (head != nullptr) {
			if (head->next != nullptr) {
				swap(head->val, head->next->val);
				head = head->next->next;
			} else {
				head = head->next;
			}
		}
		return dummy;
	}
};