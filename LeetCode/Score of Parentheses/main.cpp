class Solution {
   public:
    int scoreOfParentheses(string S) {
        int ans = 0, balance = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                balance++;
            } else {
                balance--;
                if (i > 0 && S[i - 1] == '(') {
                    ans += (1 << balance);
                }
            }
        }
        return ans;
    }
};