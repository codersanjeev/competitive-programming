class Solution {
   public:
    bool reorderedPowerOf2(int N) {
        string S = convertNumber(N);
        for (int i = 0; i < 32; i++) {
            if (S == convertNumber(1 << i)) {
                return true;
            }
        }
        return false;
    }

   private:
    string convertNumber(int N) {
        string ans = to_string(N);
        sort(ans.begin(), ans.end());
        return ans;
    }
};