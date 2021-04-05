class Solution {
   public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> mp;
        for (int i = 1; i <= 26; i++) {
            mp[keyboard[i - 1]] = i;
        }
        int curr = 1, ans = 0;
        for (const auto &ch : word) {
            int next = mp[ch];
            ans += abs(next - curr);
            curr = next;
        }
        return ans;
    }
};