#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >>t;
	while(t--){
		cin >>n;
		int ans = 0;
		while(n != 0){
			ans += n/100;
			n %= 100;
			ans += n/50;
			n %= 50;
			ans += n/10;
			n %= 10;
			ans += n/5;
			n %= 5;
			ans += n/2;
			n %= 2;
			ans += n/1;
			n %= 1;
		}
		cout <<ans <<"\n";
	}
	return 0;
}