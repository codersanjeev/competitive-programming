class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(), A.end(), [&](const int &x, const int &y) {
            return x % 2 < y % 2;
        });
        return A;
    }
};