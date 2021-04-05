class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buys(k + 1, INT_MIN);
        vector<int> sells(k + 1, 0);
        for (const auto& price : prices) {
            for (int i = 1; i <= k; i++) {
                buys[i] = max(buys[i], sells[i - 1] - price);
                sells[i] = max(sells[i], buys[i] + price);
            }
        }
        return sells[k];
    }
};