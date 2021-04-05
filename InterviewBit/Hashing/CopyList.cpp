/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode *Solution::copyRandomList(RandomListNode *A) {
	if (A == NULL) {
		return A;
	}
	RandomListNode *head = A;
	RandomListNode *cloned;
	RandomListNode *newHead = new RandomListNode(A->label);
	newHead->next = A->next;
	newHead->random = A->random;
	RandomListNode *curr = head;
	RandomListNode *temp = newHead;
	unordered_map<RandomListNode *, RandomListNode *> myMap;
	myMap.insert({head, newHead});
	curr = curr->next;
	while (curr != NULL) {
		cloned = new RandomListNode(curr->label);
		cloned->next = curr->next;
		cloned->random = curr->random;
		temp->next = cloned;
		temp = temp->next;
		myMap.insert({curr, cloned});
		curr = curr->next;
	}
	curr = A;
	temp = newHead;
	while (curr != NULL) {
		if ((myMap.find(curr->random)) != myMap.end()) {
			myMap[curr]->random = myMap[curr->random];
		} else {
			myMap[curr]->random = NULL;
		}
		curr = curr->next;
	}
	return newHead;
}
