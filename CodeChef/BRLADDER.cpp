#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q, a, b;
	cin >>q;
	while(q--){
		cin >>a >>b;
		if((abs(a-b) == 1 && max(a, b)%2 == 0 && min(a, b)%2 == 1) || 
			(abs(a-b) == 2 && a%2 == 1 && b%2 == 1) || 
			(abs(a-b) == 2 && a%2 == 0 && b%2 == 0))
			cout <<"YES\n";
		else
			cout <<"NO\n";
	}
	return 0;
}