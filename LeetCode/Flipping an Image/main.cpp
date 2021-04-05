class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &X : A) {
            reverse(X.begin(), X.end());
        }
        for (auto &X : A) {
            for (auto &Y : X) {
                Y ^= 1;
            }
        }
        return A;
    }
};