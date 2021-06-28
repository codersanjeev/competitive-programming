class Solution {
   public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0LL;
        int x = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int j = 0; j < word.size(); ++j) {
            x ^= 1 << (word[j] - 'a');
            ans += mp[x];
            for (int i = 0; i < 10; ++i) {
                ans += mp[x ^ (1 << i)];
            }
            mp[x]++;
        }
        return ans;
    }
};