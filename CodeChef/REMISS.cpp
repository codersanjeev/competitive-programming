#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, x, y;
	cin >>t;
	while(t--){
		cin >>x >>y;
		cout <<max(x, y) <<" " <<(x + y) <<"\n";
	}
	return 0;
}