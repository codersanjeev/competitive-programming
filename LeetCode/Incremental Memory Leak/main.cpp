class Solution {
   public:
    vector<int> memLeak(int x, int y) {
        int t = 1;
        while (1) {
            if (x >= y) {
                if (t > x) return {t, x, y};
                x -= t;
            } else if (x < y) {
                if (t > y) return {t, x, y};
                y -= t;
            }
            t++;
        }
        return {};
    }
};