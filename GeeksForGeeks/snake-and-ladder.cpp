/*
https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0/
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct entry {
	int vertex;
	int distance;
};

int minMoves(vector<int> board, int N) {
	vector<bool> visited(40, false);
	queue<entry> q;
	visited[1] = true;
	// push first vertex
	entry first = {1,0};
	q.push(first);
	// do DFS
	entry temp;
	while (!q.empty()) {
		temp = q.front();
		int vertex = temp.vertex;
		if (vertex==30) break;
		
		// deque front vertex and push its neighbors
		q.pop();
		for (int i=vertex+1; i<=vertex+6 && i<=30; i++) {
			if (!visited[i]) {
				visited[i] = true;
				entry a;
				a.distance = temp.distance+1;
				a.vertex = (board[i]==-1) ? i : board[i];
				q.push(a);
			}
		}
	}
	return temp.distance;
}

int main()
{
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> board(40, -1);
		for (int i=0; i<n; i++) {
			int a, b; cin >> a >> b;
			board[a] = b;
		}
		// perform dfs;
		cout << minMoves(board, 30) << endl;
	}
	return 0;
}