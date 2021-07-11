class Solution {
   public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> index(26, {-1, -1});
        for (int i = 0; i < s.size(); ++i) {
            int curr = s[i] - 'a';
            if (index[curr].first == -1)
                index[curr].first = i;
            else
                index[curr].second = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            unordered_set<char> curr;
            for (int j = index[i].first + 1; j < index[i].second; ++j) {
                curr.insert(s[j]);
            }
            ans += curr.size();
        }
        return ans;
    }
};