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
		for(int i = 1; n != 0; i += 2){
			cout <<i <<" ";
			n--;
		}
		cout <<"\n";
	}
	return 0;
}