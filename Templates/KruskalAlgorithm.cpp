#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;

   public:
    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    int find(int u) {
        if (parent[u] == -1) {
            return u;
        } else {
            return parent[u] = find(parent[u]);
        }
    }

    void merge(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
                rank[b] += rank[a];
            } else {
                parent[b] = a;
                rank[a] += rank[b];
            }
        }
    }
};

/**
 * Find Minimum Spanning Tree (MST) of given graph
 * 
 * Input: 2D array of edges of the graph, each edge is in the 
 * format [weight, source, destination] denoting an edge from Node source to 
 * Node destination having weight/cost weight.
 * also, number of nodes in the graph
 * 
 * Output: Cost/Weight of MST = Sum of edges in MST
 * 
 * Algorithm: 
 * 1. Sort the edges based on their weights/cost.
 * 2. Start adding the edges to MST from the edge with smallest weight until edge of largest weight.
 * 3. Only, add edges which does not form a cycle. Check this using Disjoing Set Union (DSU) data structure.
 * 
 * */
int kruskal(vector<vector<int>> &edges, int nodes) {
    sort(begin(edges), end(edges));
    int ans = 0, u, v, w;
    DSU *dsu = new DSU(nodes);
    for (const auto &edge : edges) {
        w = edge[0];
        u = edge[1];
        v = edge[2];
        if (dsu->find(u) != dsu->find(v)) {
            dsu->merge(u, v);
            ans += w;
        }
    }
    return ans;
}
