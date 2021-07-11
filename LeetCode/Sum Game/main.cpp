class Solution {
   public:
    bool sumGame(string num) {
        int n = num.size();
        double x = 0.0, y = 0.0;
        for (int i = 0; i < n; ++i) {
            double a = 4.5;
            if (num[i] != '?') a = num[i] - '0';
            if (i < n / 2) {
                x += a;
            } else {
                y += a;
            }
        }
        return x != y;
    }
};