class Solution {
   public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix.back().back(), ans = lo;
        auto good = [&](int ele, int k) -> bool {
            int cnt = 0;
            for (const auto& row : matrix) {
                cnt += lower_bound(cbegin(row), cend(row), ele) - cbegin(row);
            }
            return cnt < k;
        };
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (good(mid, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};