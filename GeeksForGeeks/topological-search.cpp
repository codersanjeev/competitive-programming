/* I want to be the very best like no one ever was. */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	list<int> *adj;
	void dfsutil(int node, bool visited[]);
	void topologicalSortUtil(int node, bool visited[], vector<int> &result);
public:
	Graph(int n);
	void addEdge(int v, int w);
	void dfs(int node);
	void printGraph();
	void topologicalSort();
};

Graph::Graph(int n) {
	v = n;
	adj = new list<int>[n];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::printGraph() {
	for (int i=0; i<v; i++) {
		list<int>::iterator it;
		cout << i << ": ";
		for (it=adj[i].begin(); it!=adj[i].end(); it++)
			cout << *it << " ";
		cout << endl;
	}
}

void Graph::dfsutil(int node, bool visited[]) {
	visited[node] = true;
	cout << node << " ";
	list<int>::iterator it;
	for (it=adj[node].begin(); it!=adj[node].end(); it++) {
		if (!visited[*it])
			dfsutil(*it, visited);
	}
}

void Graph::dfs(int node) {
	bool *visited = new bool[v];
	for (int i=0; i<v; i++)
		visited[i] = false;
	
	dfsutil(node, visited);
	cout << endl;
}

void Graph::topologicalSortUtil(int node, bool visited[], vector<int> &result) {
	visited[node] = true;
	list<int>::iterator it;
	for (it=adj[node].begin(); it!=adj[node].end(); it++) {
		if (!visited[*it])
			topologicalSortUtil(*it, visited, result);
	}
	result.push_back(node);
}

void Graph::topologicalSort() {
	bool *visited = new bool[v];
	for (int i=0; i<v; i++)	visited[i] = false;

	vector<int> result;
	for (int i=0; i<v; i++) {
		if (!visited[i]) topologicalSortUtil(i, visited, result);
	}
	// print the topological sort sequence
	for (int i=result.size()-1; i>=0; i--)
		cout << result[i] << " ";
	cout << endl;
}

int main() {
	Graph g(5);
	g.addEdge(1,3);
	g.addEdge(2,1);
	g.addEdge(2,4);
	g.addEdge(4,1);

	cout << "Graph is: " << endl;
	g.printGraph();
	cout << "DFS is: " << endl;
	g.dfs(2);
	cout << "TOPOLOGICAL SORT is: " << endl;
	g.topologicalSort();
}