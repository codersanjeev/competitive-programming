#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	string s;
	char ele = '4';
	cin >>t;
	while(t--){
		cin >>s;
		cout <<count(s.begin(), s.end(), ele) <<"\n";
	}
	return 0;
}