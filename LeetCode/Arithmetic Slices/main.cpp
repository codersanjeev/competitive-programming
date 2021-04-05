class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0, count = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                count++;
            } else {
                ans += ((count * (count + 1)) / 2);
                count = 0;
            }
        }
        ans += ((count * (count + 1)) / 2);
        return ans;
    }
};