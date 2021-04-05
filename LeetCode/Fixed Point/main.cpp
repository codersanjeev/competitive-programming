class Solution {
   public:
    int fixedPoint(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == i) {
                return i;
            }
        }
        return -1;
    }
};