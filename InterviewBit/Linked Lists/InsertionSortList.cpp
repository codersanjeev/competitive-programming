/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::insertionSortList(ListNode *head) {
	vector<int> temp;
	if (head == NULL || head->next == NULL) {
		return head;
	}
	while (head != NULL) {
		temp.push_back(head->val);
		head = head->next;
	}
	sort(temp.begin(), temp.end());
	ListNode *dummy = new ListNode(-1);
	ListNode *tempNode = dummy;
	for (auto ele : temp) {
		tempNode->next = new ListNode(ele);
		tempNode = tempNode->next;
	}
	return dummy->next;
}
