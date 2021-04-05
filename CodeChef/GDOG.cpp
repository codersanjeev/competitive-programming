#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, k;
	cin >>t;
	while(t--){
		int ans = INT_MIN;
		cin >>n >>k;
		for(int i = 1; i <= k; i++)
			ans = max(ans, n%i);
		cout <<ans <<"\n";
	}
	return 0;
}