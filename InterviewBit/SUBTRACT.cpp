/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int findLength(ListNode *head) {
	int ans = 0;
	while (head != NULL) {
		ans++;
		head = head->next;
	}
	return ans;
}

ListNode *advanceNode(ListNode *head, int amount) {
	int i = 0;
	while (i < amount) {
		head = head->next;
		i++;
	}
	return head;
}

ListNode *reverseNode(ListNode *head) {
	ListNode *prev = NULL;
	ListNode *prox = NULL;
	ListNode *curr = head;
	while (curr != NULL) {
		prox = curr->next;
		curr->next = prev;
		prev = curr;
		curr = prox;
	}
	return prev;
}

ListNode *Solution::subtract(ListNode *head) {
	int n = findLength(head);
	if (n == 1) {
		return head;
	}
	int mid = n / 2;
	// reverse the part after middle node
	ListNode *midNode = advanceNode(head, mid);
	ListNode *revNodeB = reverseNode(midNode);
	// rememeber middle node to fix it later
	ListNode *remMidNode = revNodeB;
	ListNode *revNodeA = head;
	int i = 0;
	while (i < mid) {
		revNodeA->val = revNodeB->val - revNodeA->val;
		revNodeA = revNodeA->next;
		revNodeB = revNodeB->next;
		i++;
	}
	// fix the 2nd reversed part
	revNodeB = reverseNode(remMidNode);
	advanceNode(head, mid - 1)->next = revNodeB;
	return head;
}
