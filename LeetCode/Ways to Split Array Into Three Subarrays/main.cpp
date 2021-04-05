#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int waysToSplit(vector<int>& nums) {
        int N = nums.size();
        for (int i = 1; i < N; i++) {
            nums[i] += nums[i - 1];
        }
        int ans = 0;
        int i = 0, j = 0, k = 0;
        while (i < N) {
            int left = nums[i];
            j = max(j, i + 1);
            while (j < N && nums[j] - left < left) {
                j++;
            }
            if (j >= N) {
                break;
            }
            k = max(k, j);
            while (k < N - 1 && nums.back() - nums[k] >= nums[k] - nums[i]) {
                k++;
            }
            ans = (ans + k - j) % mod;
            i++;
        }
        return ans;
    }

   private:
    const int mod = 1e9 + 7;
};