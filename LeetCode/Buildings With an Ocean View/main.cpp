#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans = {n - 1};
        stack<int> st;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] < heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans.push_back(i);
            }
            st.push(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};