class Solution {
   public:
    string toLowerCase(string s) {
        for (auto &ele : s) {
            if (ele >= 'A' && ele <= 'Z') {
                ele = 'a' + (ele - 'A');
            }
        }
        return s;
    }
};