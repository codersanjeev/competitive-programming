class Solution {
   public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int ones = count(cbegin(arr), cend(arr), 1);
        if (ones % 3 != 0) return {-1, -1};
        if (ones == 0) return {0, (int)arr.size() - 1};
        ones /= 3;
        int curr = 0, x = 0, y = 0, z = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 1) {
                if (curr % ones == 0) {
                    int temp = curr / ones;
                    if (temp == 0)
                        x = i;
                    else if (temp == 1)
                        y = i;
                    else
                        z = i;
                }
                ++curr;
            }
        }
        while (z != arr.size()) {
            if (arr[x] != arr[y] || arr[y] != arr[z]) {
                return {-1, -1};
            }
            ++x, ++y, ++z;
        }
        return {x - 1, y};
    }
};