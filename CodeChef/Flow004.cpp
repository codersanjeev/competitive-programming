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
		int ia = s[0] - '0';
		int ib = s[s.size()-1] - '0';
		cout <<ia+ib <<"\n";
	}
	return 0;
}