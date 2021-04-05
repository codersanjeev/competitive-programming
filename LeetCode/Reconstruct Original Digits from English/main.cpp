#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string originalDigits(string s) {
        vector<int> freq(26, 0), nums(10, 0);
        for (const auto &ch : s) {
            freq[ch - 'a'] += 1;
        }
        nums[0] = freq['z' - 'a'];
        nums[2] = freq['w' - 'a'];
        nums[4] = freq['u' - 'a'];
        nums[1] = freq['o' - 'a'] - nums[0] - nums[2] - nums[4];
        nums[3] = freq['r' - 'a'] - nums[0] - nums[4];
        nums[6] = freq['x' - 'a'];
        nums[7] = freq['s' - 'a'] - nums[6];
        nums[8] = freq['g' - 'a'];
        nums[5] = freq['v' - 'a'] - nums[7];
        nums[9] = freq['i' - 'a'] - nums[5] - nums[6] - nums[8];
        string ans = "";
        for (int i = 0; i < 10; i++) {
            ans += string(nums[i], '0' + i);
        }
        return ans;
    }
};