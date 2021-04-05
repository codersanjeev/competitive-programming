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
		if(n < 10)
			cout <<"What an obedient servant you are!\n";
		else
			cout <<"-1\n";
	}
	return 0;
}