class Solution {
   public:
    int maxArea(int h, int w, vector<int>& horizontal, vector<int>& vertical) {
        horizontal.push_back(0);
        horizontal.push_back(h);
        vertical.push_back(0);
        vertical.push_back(w);
        sort(begin(horizontal), end(horizontal));
        sort(begin(vertical), end(vertical));
        int maxHorizontalDiff = 0, maxVerticalDiff = 0;
        for (int i = 1; i < horizontal.size(); ++i) {
            maxHorizontalDiff = max(maxHorizontalDiff, horizontal[i] - horizontal[i - 1]);
        }
        for (int i = 1; i < vertical.size(); ++i) {
            maxVerticalDiff = max(maxVerticalDiff, vertical[i] - vertical[i - 1]);
        }
        return (long(maxHorizontalDiff) * long(maxVerticalDiff)) % 1000000007;
    }
};