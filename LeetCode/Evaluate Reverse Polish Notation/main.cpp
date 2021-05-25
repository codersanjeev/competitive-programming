class Solution {
   public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (const auto &ele : tokens) {
            if (ele == "+" || ele == "-" || ele == "*" || ele == "/") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if (ele == "+")
                    st.push(y + x);
                else if (ele == "-")
                    st.push(y - x);
                else if (ele == "*")
                    st.push(y * x);
                else
                    st.push(y / x);
            } else {
                st.push(stoi(ele));
            }
        }
        return st.top();
    }
};