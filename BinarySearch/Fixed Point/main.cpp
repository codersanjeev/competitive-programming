#include <vector>
using namespace std;

int solve(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid < 0 || nums[mid] < mid) {
            lo = mid + 1;
        } else {
            if (nums[mid] == mid) {
                ans = mid;
            }
            hi = mid - 1;
        }
    }
    return ans;
}