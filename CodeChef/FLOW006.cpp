#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	long long n;
	cin >>t;
	while(t--){
		cin >>n;
		long long ans = 0;
		while(n != 0){
			ans += (n%10);
			n /= 10;
		}
		cout <<ans <<"\n";
	}
	return 0;
}