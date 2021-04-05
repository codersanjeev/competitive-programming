int Solution::solve(string A) {
    stack<char> st;
    for (const auto &ele : A) {
        if (ele == '(') {
            st.push(ele);
        } else if (st.empty()) {
            return 0;
        } else {
            st.pop();
        }
    }
    return st.empty() ? 1 : 0;
}