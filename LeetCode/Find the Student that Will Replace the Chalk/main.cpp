class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        k %= accumulate(cbegin(chalk), cend(chalk), 0L);
        for (int i = 0; i < chalk.size(); ++i) {
            if (chalk[i] > k) return i;
            k -= chalk[i];
        }
        return 0;
    }
};