/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lengthA = findLength(headA);
		int lengthB = findLength(headB);
		if (lengthA < lengthB) {
			swap(lengthA, lengthB);
			swap(headA, headB);
		}
		int extra = lengthA - lengthB;
		while (extra-- && headA != nullptr) {
			headA = headA->next;
		}
		while (headA != nullptr && headB != nullptr && headA != headB) {
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}

  private:
	int findLength(ListNode *head) {
		int ans = 0;
		while (head != nullptr) {
			ans++;
			head = head->next;
		}
		return ans;
	}
};