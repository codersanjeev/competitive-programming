class Solution {
   public:
    int numWays(int n, int k) {
        if (cache.find({n, k}) != cache.end()) {
            return cache[{n, k}];
        }
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return k;
        } else if (n == 2) {
            return k * k;
        } else {
            return cache[{n, k}] = (k - 1) * (numWays(n - 1, k) + numWays(n - 2, k));
        }
    }

   private:
    map<pair<int, int>, int> cache;
};