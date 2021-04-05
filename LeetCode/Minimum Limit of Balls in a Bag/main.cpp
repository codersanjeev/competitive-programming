#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumSize(const vector<int> &nums, int maxOperations) {
        int lo = 1, hi = 1e9, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (good(nums, maxOperations, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

   private:
    bool good(const vector<int> &arr, int operations, int target) {
        int curr = 0;
        for (const auto &ele : arr) {
            if (ele > target) {
                curr += (ele - 1) / target;
            }
        }
        return curr <= operations;
    }
};