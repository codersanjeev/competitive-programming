class Solution {
   private:
    int squareSide = 0;

    bool makesquareRecursive(const vector<int> &matchsticks, int index, vector<int> &square) {
        if (index == matchsticks.size()) {
            return equal(cbegin(square) + 1, cend(square), cbegin(square));
        }
        for (int i = 0; i < 4; ++i) {
            square[i] += matchsticks[index];
            if (square[i] <= squareSide && makesquareRecursive(matchsticks, index + 1, square)) {
                return true;
            }
            square[i] -= matchsticks[index];
        }
        return false;
    }

   public:
    bool makesquare(vector<int> &matchsticks) {
        sort(begin(matchsticks), end(matchsticks), greater<int>());
        int sum = accumulate(cbegin(matchsticks), cend(matchsticks), 0);
        if (sum % 4 != 0) return false;
        squareSide = sum / 4;
        vector<int> square(4, 0);
        return makesquareRecursive(matchsticks, 0, square);
    }
};