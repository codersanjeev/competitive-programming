class Solution {
   public:
    bool isStrobogrammatic(string n) {
        reverse(n.begin(), n.end());
        string m = "";
        for (const auto &ele : n) {
            if (mp[ele - '0'] == -1) {
                return false;
            }
            m += to_string(mp[ele - '0']);
        }
        reverse(n.begin(), n.end());
        return m == n;
    }

   private:
    vector<int> mp = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
};