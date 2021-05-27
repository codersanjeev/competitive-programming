class Solution {
   public:
    int maxProduct(vector<string> &words) {
        int n = words.size(), ans = 0;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                arr[i] = arr[i] | (1 << (words[i][j] - 'a'));
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((arr[i] & arr[j]) == 0) {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }
};