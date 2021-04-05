#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, p, q, r;
	cin >>t;
	while(t--){
		int ans = 0;
		cin >>n >>p >>q >>r;
		for(int i = 1; i <= n; i++){
			if((i%p == 0 && i%q != 0 && i%r != 0) || 
			   (i%q == 0 && i%r != 0 && i%p != 0) ||
			   (i%r == 0 && i%p != 0 && i%q != 0))
				ans++;
		}
		cout <<ans <<"\n";
	}
	return 0;
}