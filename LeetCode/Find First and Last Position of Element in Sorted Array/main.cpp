#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int lo = findLowerBound(nums, target);
        int hi = findUpperBound(nums, target);
        return {lo, hi};
    }

   private:
    int findLowerBound(const vector<int> &arr, int target) {
        int lo = 0, hi = arr.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) {
                ans = mid;
                hi = mid - 1;
            } else if (arr[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    int findUpperBound(const vector<int> &arr, int target) {
        int lo = 0, hi = arr.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) {
                ans = mid;
                lo = mid + 1;
            } else if (arr[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};