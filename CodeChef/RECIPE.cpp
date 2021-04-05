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
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >>arr[i];
		int gcd = arr[0];
		for(int i = 1; i < n; i++)
			gcd = __gcd(gcd, arr[i]);
		for(int i = 0; i < n; i++)
			arr[i] /= gcd;
		for(int i = 0; i < n; i++)
			cout <<arr[i] <<" ";
		cout <<"\n";
	}
	return 0;
}