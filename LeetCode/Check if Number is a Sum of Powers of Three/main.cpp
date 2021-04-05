class Solution {
   public:
    bool subsetSum(const vector<int> &arr, int sum) {
        int n = arr.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            int curr = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    curr += arr[i];
                }
            }
            if (curr == sum) {
                return true;
            }
        }
        return false;
    }

    bool checkPowersOfThree(int n) {
        vector<int> arr = {1};
        while (arr.back() <= (int)1e7) {
            arr.push_back(3 * arr.back());
        }
        return subsetSum(arr, n);
    }
};