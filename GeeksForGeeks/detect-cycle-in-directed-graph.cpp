/*
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool dfs(int N, vector<int> adj[], vector<bool> &visited, unordered_set<int> &s) {
	if (visited[N] && s.count(N)) {
		return true;
	}
	visited[N] = true;
	s.insert(N);
	
	vector<int>::iterator it;
	for (it=adj[N].begin(); it!=adj[N].end(); it++) {
		if (dfs(*it, adj, visited, s))
			return true;
	}
	
	s.erase(N);
	return false;
}

bool isCyclic(int V, vector<int> adj[])
{
	vector<bool> visited(V+1, false);
	
	for (int i=0; i<V; i++) {
		if (!visited[i]) {
			unordered_set<int> s;
			if (dfs(i, adj, visited, s))
				return true;
		}
	}
	return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
		
		int v, e;
		cin >> v >> e;
		
		vector<int> adj[v];
		
		for(int i =0;i<e;i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		
		cout << isCyclic(v, adj) << endl;
		
	}
	
	return 0;
}  // } Driver Code Ends