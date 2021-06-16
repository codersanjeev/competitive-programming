class Solution {
   private:
    vector<string> ans;

    void generateParenthesisRecursive(int n, int l, int r, string s) {
        if (l == n && r == n) {
            ans.push_back(s);
            return;
        }
        if (l < n) {
            generateParenthesisRecursive(n, l + 1, r, s + '(');
        }
        if (r < l) {
            generateParenthesisRecursive(n, l, r + 1, s + ')');
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisRecursive(n, 0, 0, "");
        return ans;
    }
};