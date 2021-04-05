class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisUtil(n, 0, 0, "");
        return ans;
    }

   private:
    vector<string> ans;

    void generateParenthesisUtil(int n, int l, int r, string s) {
        if (l == n && r == n) {
            ans.push_back(s);
            return;
        }
        if (l < n) {
            generateParenthesisUtil(n, l + 1, r, s + '(');
        }
        if (r < l) {
            generateParenthesisUtil(n, l, r + 1, s + ')');
        }
    }
};