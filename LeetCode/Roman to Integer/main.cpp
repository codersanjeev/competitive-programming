class Solution {
   public:
    int romanToInt(string s) {
        for (int i = 0; i < 7; i++) {
            mp[chars[i]] = values[i];
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && mp[s[i]] > mp[s[i - 1]]) {
                ans -= mp[s[i - 1]];
                ans -= mp[s[i - 1]];
            }
            ans += mp[s[i]];
        }
        return ans;
    }

   private:
    unordered_map<char, int> mp;
    vector<char> chars = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> values = {1, 5, 10, 50, 100, 500, 1000};
};