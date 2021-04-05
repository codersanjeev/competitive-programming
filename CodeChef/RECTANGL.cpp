#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, a, b, c, d;
	cin >>t;
	while(t--){
		cin >>a >>b >>c >>d;
		if(a == b){
			if(c == d){
				cout <<"YES\n";
			}
			else{
				cout <<"NO\n";
			}
		}
		else if(a == c){
			if(b == d){
				cout <<"YES\n";
			}
			else{
				cout <<"NO\n";
			}
		}
		else if(a == d){
			if(b == c){
				cout <<"YES\n";
			}
			else{
				cout <<"NO\n";
			}
		}
		else{
			cout <<"NO\n";
		}
	}
	return 0;
}