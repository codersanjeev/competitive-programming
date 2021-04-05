/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
 
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout <<#x <<" " <<x <<endl;

void dfs(int node, vector<bool> &visited, vector<int> adj[]){
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]])
            dfs(adj[node][i], visited, adj);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, x;
    cin >>n >>m;
    vector<int> adj[n+1];
    while(m--){
        cin >>a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >>x;
    vector<bool> visited(n+1, false);
    dfs(x, visited, adj);
    int connectedComponents = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            // cout <<i <<" ";
            connectedComponents++;
        }
    }
    cout <<connectedComponents <<"\n";
    return 0;
}
