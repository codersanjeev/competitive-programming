class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, visited, sr, sc, image.size(), image[0].size(), newColor, image[sr][sc]);
        return image;
    }

   private:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    void dfs(vector<vector<int>> &image, vector<vector<bool>> &visited, int i, int j, int n, int m, int colorOne, int colorTwo) {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j]) {
            return;
        }
        if (image[i][j] != colorTwo) {
            return;
        }
        image[i][j] = colorOne;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            dfs(image, visited, i + dx[k], j + dy[k], n, m, colorOne, colorTwo);
        }
    }
};