/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
#define SIZE 100005
using namespace std;

// Segment Tree and Sieve...

vector<int> tree[10*SIZE];
vector<int> p[SIZE];
void build(int start, int end, int node){
	if(start == end){
		tree[node] = p[start];
		return;
	}
	int mid = (start + end) >> 1;
	build(start, mid, 2 * node);
	build(mid + 1, end, 2 * node + 1);
	merge(tree[2*node].begin(), tree[2*node].end(), tree[2*node+1].begin(), tree[2*node+1].end(), back_inserter(tree[node]));
}

int query(int node, int start, int end, int l, int r, int x, int y){
	if(start > end)
		return 0;
	if(start > r || end < l)
		return 0;
	if(start >= l && end <= r){
		int left = lower_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
		int right = upper_bound(tree[node].begin(), tree[node].end(), y) - tree[node].begin();
		return right - left;
	}
	int mid = (start + end) >> 1;
	return query(2*node, start, mid, l, r, x, y) + query(2*node+1, mid+1, end, l, r, x, y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
	cin >>n;
	for(int i = 0; i < n; i++){
		cin >>num;
		while(num%2 == 0){
			p[i].push_back(2);
			num /= 2;
		}
		for(int j = 3; j*j <= (num); j++){
			while(num%j == 0){
				p[i].push_back(j);
				num /= j;
			}
		}
		if(num > 1)
			p[i].push_back(num);
	}
	build(0, n-1, 1);
	int m;
	cin >>m;
	for(int i = 0; i < m; i++){
		int l, r, x, y;
		cin >>l >>r >>x >>y;
		cout <<query(1,0,n-1,--l,--r,x,y) <<"\n";
	}
    return 0;
}