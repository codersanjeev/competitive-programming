class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int K) {
        int n = grid.size(), m = grid[0].size(), k = 0;
        vector<int> arr(n * m);
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        		arr[k++] = grid[i][j];
        	}
        }
        K %= arr.size();
        reverseUtil(arr, arr.size() - K, arr.size() - 1);
        reverseUtil(arr, 0, arr.size() - K - 1);
        reverseUtil(arr, 0, arr.size() - 1);
        k = 0;
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        		grid[i][j] = arr[k++];
        	}
        }
        return grid;
    }
private:
    void reverseUtil(vector<int> &arr, int i, int j) {
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};