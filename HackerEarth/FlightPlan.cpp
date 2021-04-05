#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> g[], int x, int y, int n){
	// to store if node is visited or not
	bool flag[n]{false};
	// store the distance of ith node form src
	int dist[n]{INT_MAX};
	// store the previous node in shortest path
	int prev[n]{-1};

	queue<int> q;
	// starting node = x
	q.push(x);
	flag[x] = true;
	dist[x] = 0;

	while(!q.empty()){
		int vert = q.front();
		q.pop();
		for(int eachVert : g[vert]){
			if(!flag[eachVert]){
				flag[eachVert] = true;
				prev[eachVert] = vert;
				dist[eachVert] = dist[vert] + 1;
				q.push(eachVert);
			}
		}
	}

	cout <<dist[y] + 1 <<endl;

	stack<int> ans;
	ans.push(y+1);
	while(y != x){
		ans.push(prev[y] + 1);
		y = prev[y];
	}
	while(!ans.empty()){
		cout <<ans.top() <<" ";
		ans.pop();
	}
	cout <<endl;
}

int main(){
	int n, m, t, c, u, v, x, y;
	cin >>n >>m >>t >>c;
	vector<int> g[n];
	for(int i = 1; i <= m; i++){
		cin >>u >>v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	cin >>x >>y;
	bfs(g, x-1, y-1, n);
	return 0;
}