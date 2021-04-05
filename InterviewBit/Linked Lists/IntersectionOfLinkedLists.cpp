/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int getLength(ListNode *l) {
	int len = 0;
	while (l != 0) {
		len++;
		l = l->next;
	}
	return len;
}

ListNode *getIntersection(ListNode *l1, ListNode *l2, int d) {
	while (d != 0) {
		l1 = l1->next;
		d--;
	}
	if (l1 == l2) {
		return l1;
	}
	while (l1 != NULL && l2 != NULL) {
		if (l1 == l2) {
			return l1;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return NULL;
}

ListNode *Solution::getIntersectionNode(ListNode *l1, ListNode *l2) {
	int m = getLength(l1);
	int n = getLength(l2);
	if (m == 0 || n == 0) {
		return  NULL;
	}
	if (m > n) {
		return getIntersection(l1, l2, m - n);
	} else {
		return getIntersection(l2, l1, n - m);
	}
}
