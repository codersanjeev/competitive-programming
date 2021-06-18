class Solution {
   private:
    int fill(const string &s, const char &ch) {
        int answer = 0;

        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != ch) ++answer;
        }

        return answer;
    }

   public:
    int minSwaps(string s) {
        int N = s.size(), ones = count(s.begin(), s.end(), '1'), zeros = N - ones;

        if (abs(zeros - ones) > 1) return -1;

        int x = fill(s, '1'), y = fill(s, '0');

        if (ones > zeros) {
            return x;

        } else if (ones < zeros) {
            return y;

        } else {
            return min(x, y);
        }
    }
};