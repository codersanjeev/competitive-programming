#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string x, y;
	cin >>t;
	while(t--){
		bool flag = true;
		cin >>x >>y;
		for(int i = 0; i < x.size(); i++){
			if(x[i] != y[i] && x[i] != '?' && y[i] != '?'){
				flag = false;
				break;
			}
		}
		if(flag)
			cout <<"Yes\n";
		else
			cout <<"No\n";
	}
	return 0;
}