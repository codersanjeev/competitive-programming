class Solution {
   public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        stable_sort(begin(arr), end(arr), [&](const int &a, const int &b) -> bool {
            return abs(a - x) < abs(b - x);
        });
        auto ans = vector<int>(cbegin(arr), cbegin(arr) + k);
        sort(begin(ans), end(ans));
        return ans;
    }
};