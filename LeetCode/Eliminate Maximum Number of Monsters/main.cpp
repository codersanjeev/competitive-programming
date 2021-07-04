class Solution {
   public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        vector<int> time(dist.size());
        for (int i = 0; i < dist.size(); ++i) {
            time[i] = dist[i] / speed[i];
            if (dist[i] % speed[i] > 0) ++time[i];
        }
        sort(begin(time), end(time));
        int ans = 1;
        for (int i = 0; i < time.size(); ++i) {
            if (ans > time[i]) {
                ans = i + 1;
                break;
            }
            ++ans;
        }
        return ans - 1;
    }
};