#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >>t;
	while(t--){
		string s;
		cin >>s;
		sort(s.begin(), s.end());
		bool flag = true;
		for(int i = 0; i < s.size()-1; i++){
			if(s[i+1] - s[i] != 1){
				flag = false;
				break;
			}
		}
		if(flag)
			cout <<"YES\n";
		else
			cout <<"NO\n";
	}
	return 0;
}