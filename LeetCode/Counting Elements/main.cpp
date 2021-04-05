class Solution {
   public:
    int countElements(vector<int>& arr) {
        multiset<int> st(arr.begin(), arr.end());
        int ans = 0;
        auto it = st.begin();
        while (it != st.end()) {
            int y = (*it) + 1;
            if (st.count(y) > 0) {
                ans++;
            }
            it++;
        }
        return ans;
    }
};