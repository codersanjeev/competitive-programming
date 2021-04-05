#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, x, y;
	cin >>t;
	while(t--){
		cin >>n;
		for(int i = 0; i < n; i++)
			cin >>x >>y;
		int ans = 1;
		for(int i = 2; i <= n; i++)
			ans ^= i;
		cout <<ans <<"\n";
	}
	return 0;
}