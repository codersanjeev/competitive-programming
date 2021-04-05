auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size(), s = accumulate(arr.begin(), arr.end(), 0);
        if (s % 3 != 0) return false;
        for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
        bool A = false, B = false, C = false;
        for (const auto &ele : arr) {
        	if (!A && ele == s / 3) {
        		A = true;
        	} else if (A && !B && ele == (2 * s) / 3) {
        		B = true;
        	} else if (A && B && !C && ele == s) {
        		C = true;
        	}
        }
        return A && B && C;
    }
};