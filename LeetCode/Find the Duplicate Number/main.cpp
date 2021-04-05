class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (const auto& ele : nums) {
            if (st.count(ele) > 0) {
                return ele;
            }
            st.insert(ele);
        }
        return -1;
    }
};