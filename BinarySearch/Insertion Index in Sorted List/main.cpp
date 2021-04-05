#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= target) {
            ans = mid + 1;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}