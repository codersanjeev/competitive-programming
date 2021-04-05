class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (const auto &ele : nums) {
            bool isEven = digitsCount(ele);
            if (isEven) ans++;
        }
        return ans;
    }
private:
    int digitsCount(int n) {
        if (n >= 10 && n <= 99) return true;
        if (n >= 1000 && n <= 9999) return true;
        if (n == 100000) return true;
        return false;
    }
};