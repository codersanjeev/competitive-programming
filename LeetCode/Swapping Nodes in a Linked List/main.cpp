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
	ListNode *swapNodes(ListNode *head, int k) {
		vector<int> temp;
		while (head != nullptr) {
			temp.push_back(head->val);
			head = head->next;
		}
		int n = temp.size();
		swap(temp[k - 1], temp[n - k]);
		ListNode *ans = new ListNode();
		ListNode *dummy = ans;
		for (const auto &ele : temp) {
			dummy->next = new ListNode(ele);
			dummy = dummy->next;
		}
		return ans->next;
	}
};