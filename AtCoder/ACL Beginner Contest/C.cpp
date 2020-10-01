/*Author -> Sambhu show(JGEC)*/
#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define itc ll t;cin>>t;while(t--)
#define PI 3.141592653589793238
#define Max(a,b,c) max(a,max(b,c));
#define Min(a,b,c) min(a,min(b,c));
#define all(v) v.begin(),v.end()
#define ll long long int
#define ld long double
#define pb push_back
#define eb emplace_back
#define gcd(a,b) __gcd(a,b)
#define fi first
#define se second
#define endl "\n"
const int N=1e5+5;
vector<int> adj[N];
bool vist[N];
void dfs(int node)
{
	vist[node]=1;
	for(auto child: adj[node])
		if(!vist[child])
			dfs(child);
}
void solve()
{
	int n,m;
	cin>>n>>m;

	while(m--)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!vist[i])
			{dfs(i);
			ans++;}
	}
	cout<<ans-1<<endl;
}
int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	fio
	//itc
	solve();

	return 0;
}
