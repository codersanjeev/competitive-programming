class Solution {
   public:
    int countLetters(string S) {
        int N = S.size(), ans = 0, cnt = 1;
        char ch = S[0];
        for (int i = 1; i < N; i++) {
            if (S[i] != ch) {
                ans += (cnt * (cnt + 1)) / 2;
                ch = S[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans += (cnt * (cnt + 1)) / 2;
        return ans;
    }
};