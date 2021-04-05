#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (const auto& ele : nums) {
            if (i < 2 || ele > nums[i - 2]) {
                nums[i++] = ele;
            }
        }
        return i;
    }
};