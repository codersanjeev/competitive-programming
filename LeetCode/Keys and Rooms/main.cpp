#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int u) {
        if (visited[u]) return;
        visited[u] = true;
        for (const auto &v : rooms[u]) {
            dfs(rooms, visited, v);
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int N = rooms.size();
        vector<bool> visited(N, false);
        dfs(rooms, visited, 0);
        for (const auto &ele : visited) {
            if (ele == false) {
                return false;
            }
        }
        return true;
    }
};