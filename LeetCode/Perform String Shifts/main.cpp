class Solution {
   public:
    string stringShift(string s, vector<vector<int>> &shift) {
        int n = s.size();
        for (const auto &ele : shift) {
            if (ele[0] == 0) {
                leftRotate(s, ele[1] % n);
            } else {
                rightRotate(s, ele[1] % n);
            }
        }
        return s;
    }

   private:
    void leftRotate(string &s, int amount) {
        reverseString(s, 0, amount - 1);
        reverseString(s, amount, s.size() - 1);
        reverseString(s, 0, s.size() - 1);
    }

    void rightRotate(string &s, int amount) {
        leftRotate(s, s.size() - amount);
    }

    void reverseString(string &s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
};