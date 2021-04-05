#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, k;
	cin >>t;
	while(t--){
		cin >>n >>k;
		int ele;
		long ans = 0;
		for(int i = 0; i < n; i++){
			cin >>ele;
			int r = ele%k;
			if(ele >= k)
				ans += min(r, k-r);
			else
				ans += k-r;
		}
		cout <<ans <<"\n";
	}
	return 0;
}