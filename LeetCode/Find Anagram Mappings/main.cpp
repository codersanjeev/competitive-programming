class Solution {
   public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        for (int i = 0; i < B.size(); i++) {
            mp[B[i]] = i;
        }
        vector<int> ans(A.size());
        for (int i = 0; i < A.size(); i++) {
            ans[i] = mp[A[i]];
        }
        return ans;
    }
};