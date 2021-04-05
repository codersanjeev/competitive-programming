#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, t, ans = 0;
	cin >>n >>k;
	while(n--){
		cin >>t;
		if(t%k == 0)
			ans++;
	}
	cout <<ans <<"\n";
	return 0;
}