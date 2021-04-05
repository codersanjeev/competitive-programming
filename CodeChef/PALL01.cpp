#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >>t;
	string s;
	while(t--){
		cin >>s;
		string y(s);
		reverse(y.begin(), y.end());
		if(s == y)
			cout <<"wins\n";
		else
			cout <<"losses\n";
	}
	return 0;
}