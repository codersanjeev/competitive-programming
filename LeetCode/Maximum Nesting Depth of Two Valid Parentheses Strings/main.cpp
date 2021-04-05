class Solution {
   public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size(), depth = 0;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depth++;
            }
            ans[i] = depth % 2;
            if (seq[i] == ')') {
                depth--;
            }
        }
        return ans;
    }
};