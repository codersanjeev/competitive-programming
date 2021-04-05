/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode *solve(LLNode *node) {
	LLNode *prev = nullptr, *curr = node;
	while (curr != nullptr) {
		LLNode *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}