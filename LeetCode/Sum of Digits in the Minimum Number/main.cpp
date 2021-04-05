class Solution {
   public:
    int sumOfDigits(vector<int>& A) {
        int mn = *min_element(A.begin(), A.end()), cnt = 0;
        while (mn > 0) {
            cnt += (mn % 10);
            mn /= 10;
        }
        return cnt % 2 == 0;
    }
};