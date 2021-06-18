class Solution {
   public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int lo = 1, hi = 1e9, ans = -1;
        auto f = [&](int speed) -> bool {
            double curr = 0;
            for (int i = 0; i < dist.size(); ++i) {
                double delta = (dist[i] * 1.0) / speed;
                if (i == dist.size() - 1 && curr + delta <= hour) {
                    return true;
                }
                curr += ceil(delta);
            }
            return curr <= hour;
        };
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};