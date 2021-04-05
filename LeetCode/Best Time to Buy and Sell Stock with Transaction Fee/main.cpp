#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = prices[0] * -1, N = prices.size();
        for (int i = 1; i < N; i++) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};