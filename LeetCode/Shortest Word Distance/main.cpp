class Solution {
   public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> X, Y;
        int index = 0, ans = INT_MAX;
        for (const auto& ele : words) {
            if (ele == word1) {
                X.push_back(index);
            } else if (ele == word2) {
                Y.push_back(index);
            }
            index++;
        }
        for (const auto& x : X) {
            for (const auto& y : Y) {
                ans = min(ans, abs(x - y));
            }
        }
        return ans;
    }
};