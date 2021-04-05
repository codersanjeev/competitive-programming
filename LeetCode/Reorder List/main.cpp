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
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr) {
			return;
		}
		ListNode *p1 = head, *p2 = head;
		while (p2->next != nullptr && p2->next->next != nullptr) {
			p1 = p1->next;
			p2 = p2->next->next;
		}
		ListNode *previousMiddle = p1, *previousCurrent = p1->next;
		while (previousCurrent->next != nullptr) {
			ListNode *current = previousCurrent->next;
			previousCurrent->next = current->next;
			current->next = previousMiddle->next;
			previousMiddle->next = current;
		}
		p1 = head;
		p2 = previousMiddle->next;
		while (p1 != previousMiddle) {
			previousMiddle->next = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p1 = p2->next;
			p2 = previousMiddle->next;
		}
	}
};