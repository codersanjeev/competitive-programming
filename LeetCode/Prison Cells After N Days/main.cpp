class Solution {
   public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N) {
        // cells[i] = 1 => occupied
        // cells[i] = 0 => vacant
        // if (cells[i - 1] == cells[i + 1]) => cells[i] = 1
        // else cells[i] = 0
        vector<int> arr(8);
        vector<vector<int>> seen;
        while (N--) {
            for (int i = 1; i < 7; i++) {
                if (cells[i - 1] == cells[i + 1]) {
                    arr[i] = 1;
                } else {
                    arr[i] = 0;
                }
            }
            if (!seen.empty() && seen.front() == arr) {
                return seen[N % seen.size()];
            } else {
                seen.push_back(arr);
            }
            cells = arr;
        }
        return arr;
    }
};