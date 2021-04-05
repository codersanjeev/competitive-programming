#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t, n, b, m;
	cin >>t;
	while(t--){
		cin >>n >>b >>m;
		long ans = 0;
		while(n){
			int x = (n+1) / 2;
			ans += x * m;
			n -= x;
			if(n)
				ans += b;
			m *= 2;
		}
		cout <<ans <<"\n";
	}
	return 0;
}