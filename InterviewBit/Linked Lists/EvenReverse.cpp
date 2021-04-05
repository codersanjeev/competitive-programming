ListNode *Solution::solve(ListNode *A) {
    ListNode *node = A;
    stack<int> st;
    int cnt = 1;
    while (node != nullptr) {
        if (cnt % 2 == 0) {
            st.push(node->val);
        }
        cnt++;
        node = node->next;
    }
    cnt = 1;
    node = A;
    while (node != nullptr) {
        if (cnt % 2 == 0) {
            node->val = st.top();
            st.pop();
        }
        cnt++;
        node = node->next;
    }
    return A;
}