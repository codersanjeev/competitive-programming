#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string a, b;
	cin >>t;
	while(t--){
		bool flag = false;
		cin >>a >>b;
		for(int i = 0; i < a.size(); i++){
			if(b.find(a[i]) != string::npos){
				flag = true;
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