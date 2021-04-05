class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128, -1);
        int left = 0, right = 0, ans = 0, n = s.size();
        while (right < n) {
            char ch = s[right];
            int index = chars[ch];
            if (index != -1 && left <= index && index <= right) {
                left = index + 1;
            }
            ans = max(ans, right - left + 1);
            chars[ch] = right;
            right++;
        }
        return ans;
    }
};