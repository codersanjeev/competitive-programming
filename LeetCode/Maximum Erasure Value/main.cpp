#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0, ans = 0, fans = 0;
        set<int> st;
        while (i < n && j < n) {
            if (st.count(nums[j]) == 0) {
                ans += nums[j];
                fans = max(fans, ans);
                st.insert(nums[j]);
                j++;
            } else {
                ans -= nums[i];
                st.erase(nums[i]);
                i++;
            }
        }
        return fans;
    }
};