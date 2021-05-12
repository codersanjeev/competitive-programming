class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, curr = 0;
        for (int i = 0; i < k; ++i) curr += cardPoints[i];
        int i = cardPoints.size() - 1, j = k - 1;
        ans = curr;
        while (j >= 0) {
            curr -= cardPoints[j];
            curr += cardPoints[i];
            ans = max(ans, curr);
            --j;
            --i;
        }
        return ans;
    }
};
