class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());
        int n = arr.size(), idx = 0;
        if ((mx - mn) % (n - 1) != 0) return false;
        int d = (mx - mn) / (n - 1);
        set<int> st(arr.begin(), arr.end());
        while (idx < n) {
            if (st.count(mn) == 0) {
                return false;
            }
            mn += d;
            idx++;
        }
        return true;
    }
};