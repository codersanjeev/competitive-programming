#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    s[st.top()] = s[i] = '*';
                    st.pop();
                }
            }
        }
        int curr = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                curr += 1;
            } else {
                ans = max(ans, curr);
                curr = 0;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};