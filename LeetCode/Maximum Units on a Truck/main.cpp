class Solution {
   public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        int ans = 0;
        for (auto& boxType : boxTypes) {
            if (truckSize <= 0) break;
            int curr = min(truckSize, boxType[0]);
            ans += boxType[1] * curr;
            boxType[0] -= curr;
            truckSize -= curr;
        }
        return ans;
    }
};