#include <bits/stdc++.h>
using namespace std;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

/**
 * Input: 
 *  adj: Adjacency List of Graph with <weight, node_b> as pair structure
 *  u: Start node for Prim's Algorithm
 *  nodes: Number of Nodes in the Graph
 * 
 * Output: Weight/Cost of MST of given graph
 * 
 * Algorithm:
 * 1. Maintain two sets of vertices, one that are in growing spanning tree and one 
 *      that are not in growing spanning tree.
 * 2. Select cheapest vertex connected to growing spanning tree and not in the growing spanning
 *      tree and add it to growing spanning tree. This can be achieved using a Min Heap.
 * 3. Check for cycles, use a boolean visited array for that.
 * */
int prim(const vector<pair<int, int>> adj[], int u, int nodes) {
    min_heap<pair<int, int>> heap;
    vector<bool> visited(nodes, false);
    int ans = 0, v, w;
    heap.push(make_pair(0, u));
    while (!heap.empty()) {
        auto curr = heap.top();
        heap.pop();
        w = curr.first;
        v = curr.second;
        if (visited[v]) continue;
        ans += w;
        visited[v] = true;
        for (const auto &ele : adj[v]) {
            heap.push(ele);
        }
    }
    return ans;
}
