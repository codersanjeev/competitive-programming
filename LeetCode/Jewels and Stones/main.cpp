class Solution {
   public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> seen(jewels.begin(), jewels.end());
        int ans = 0;
        for (const auto &ch : stones) {
            if (seen.count(ch) > 0) {
                ans++;
            }
        }
        return ans;
    }
};