/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<long long>> board(3, vector<long long>(3));
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cin >>board[i][j];
		}
	}
	long long n, ele;
	cin >>n;	
	while(n--) {
		cin >>ele;
		for(long long i = 0; i < 3; i++) {
			for(long long j = 0; j < 3; j++) {
				if(board[i][j] == ele) {
					board[i][j] = -1;
				}
			}
		}	
	}
	bool flag = false;
	if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1)
		flag = true;
	if(board[0][2] == -1 && board[1][1] == -1 && board[2][0] == -1)
		flag = true;
	if(board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1)
		flag = true;
	if(board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1)
		flag = true;
	if(board[2][0] == -1 && board[2][1] == -1 && board[2][2] == -1)
		flag = true;
	if(board[0][0] == -1 && board[1][0] == -1 && board[2][0] == -1)
		flag = true;
	if(board[0][1] == -1 && board[1][1] == -1 && board[2][1] == -1)
		flag = true;
	if(board[0][2] == -1 && board[1][2] == -1 && board[2][2] == -1)
		flag = true;
	if(flag)
		cout <<"Yes";
	else 
		cout <<"No";
	return 0;
}
