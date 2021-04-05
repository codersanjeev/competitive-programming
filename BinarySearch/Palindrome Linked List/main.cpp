/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

LLNode *reverse(LLNode *node) {
	LLNode *prev = nullptr, *curr = node;
	while (curr != nullptr) {
		LLNode *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

bool solve(LLNode *node) {
	LLNode *slow = node, *fast = node;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	LLNode *rev = reverse(slow);
	while (rev != nullptr) {
		if (node->val != rev->val) {
			return false;
		}
		node = node->next;
		rev = rev->next;
	}
	return true;
}