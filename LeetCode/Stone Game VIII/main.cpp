class Solution {
   public:
    int stoneGameVIII(vector<int> &stones) {
        for (int i = 1; i < stones.size(); ++i) stones[i] += stones[i - 1];
        return solve(stones, 0);
    }

   private:
    int solve(const vector<int> &stones, int index) {
        if (index == stones.size() - 2) return stones.back();
        int next = solve(stones, index + 1);
        return max(next, stones[index + 1] - next);
    }
};