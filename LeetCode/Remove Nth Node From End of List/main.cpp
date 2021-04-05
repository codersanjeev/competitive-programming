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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int N = lengthOfList(head);
		N -= n;
		ListNode *dummy = new ListNode();
		dummy->next = head;
		ListNode *temp = dummy;
		while (N--) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
		return dummy->next;
	}

  private:
	int lengthOfList(ListNode *head) {
		int len = 0;
		while (head != nullptr) {
			len++;
			head = head->next;
		}
		return len;
	}
};