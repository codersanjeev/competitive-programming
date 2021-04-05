int Solution::solve(int numCourses, vector<int> &B, vector<int> &C) {
    vector<int> adj[numCourses];
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> prerequisites;
    for (int i = 0; i < B.size(); i++) {
        vector<int> temp = {B[i] - 1, C[i] - 1};
        prerequisites.push_back(temp);
    }
    for (const auto &vu : prerequisites) {
        int u = vu[1];
        int v = vu[0];
        adj[u].push_back(v);
        indegree[v]++;
    }
    int nodes = 0;
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topologicalOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
        topologicalOrder.push_back(u);
        nodes++;
    }
    return nodes == numCourses;
}
