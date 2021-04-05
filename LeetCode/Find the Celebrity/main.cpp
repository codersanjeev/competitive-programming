/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
   public:
    int findCelebrity(int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (knows(ans, i)) {
                ans = i;
            }
        }
        return isCelebrity(ans, n) ? ans : -1;
    }

   private:
    bool isCelebrity(int i, int n) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (knows(i, j) || knows(j, i) == false) {
                return false;
            }
        }
        return true;
    }
};