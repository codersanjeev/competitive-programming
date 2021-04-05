#include<bits/stdc++.h>
using namespace std;

// returns x^y % m
long long solve(long long x, long long y, long long m = 1000000007){
	long long ans = 1;
	while(y){
		if(y&1)
			ans = (ans * x) % m;
		x = (x*x) % m;
		y >>= 1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t, n;
	cin >>t;
	while(t--){
		cin >>n;
		cout <<solve(2, n) - 1 <<"\n";
	}
	return 0;
}