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
	bool isPalindrome(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		slow = reverseList(slow);
		while (slow != nullptr) {
			if (slow->val != head->val) {
				return false;
			}
			slow = slow->next;
			head = head->next;
		}
		return true;
	}

	ListNode *reverseList(ListNode *head) {
		ListNode *previousNode = nullptr;
		ListNode *currentNode = head;
		while (currentNode != nullptr) {
			ListNode *nextNode = currentNode->next;
			currentNode->next = previousNode;
			previousNode = currentNode;
			currentNode = nextNode;
		}
		return previousNode;
	}

};