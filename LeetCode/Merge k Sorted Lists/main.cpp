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

	struct comp {
	  public:
		bool operator()(const ListNode *x, const ListNode *y) {
			return x->val > y->val;
		}
	};

	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue <ListNode *, vector<ListNode *>, comp> pq;
		ListNode *ans = new ListNode();
		ListNode *node = ans;
		for (const auto &ele : lists) {
			if (ele != nullptr) {
				pq.push(ele);
			}
		}
		while (!pq.empty()) {
			auto curr = pq.top();
			pq.pop();
			node->next = new ListNode(curr->val);
			node = node->next;
			if (curr->next != nullptr) {
				pq.push(curr->next);
			}
		}
		return ans->next;
	}
};