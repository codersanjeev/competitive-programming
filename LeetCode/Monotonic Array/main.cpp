auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool inc = true, dec = true;
        for (int i = 1; i < n; i++) {
        	inc &= (A[i] >= A[i - 1]);
        	dec &= (A[i] <= A[i - 1]);
        }
        return inc || dec;
    }
};