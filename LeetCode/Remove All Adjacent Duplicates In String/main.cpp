class Solution {
   public:
    string removeDuplicates(string S) {
        stack<char> st;
        bool ok;
        for (const auto &ch : S) {
            ok = false;
            while (!st.empty() && st.top() == ch) {
                st.pop();
                ok = true;
            }
            if (ok) continue;
            st.push(ch);
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};