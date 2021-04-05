/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::reorderList(ListNode *head) {
	unordered_map<int, ListNode *> mp;
	for (int i = 1; head != NULL; i++) {
		mp[i] = head;
		head = head->next;
	}
	ListNode *dummy = new ListNode(0);
	ListNode *curr = dummy;
	int i = 1, j = mp.size();
	while (i <= j) {
		curr->next = mp[i];
		if (i != j) {
			mp[i]->next = mp[j];
		}
		mp[j]->next = NULL;
		curr = mp[j];
		i++;
		j--;
	}
	return dummy->next;
}
