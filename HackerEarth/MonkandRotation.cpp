#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long t, n, k;
	cin >>t;
	while(t--){
		cin >>n >>k;
		k %= n;
		long long a[n];
		for(long long i=0; i<n; i++){
			cin >>a[i];
		}
		for(long long i=0; i<n; i++){
		    cout <<a[(i+(n-k))%n] <<" ";
		}
		cout <<"\n";
	}
	return 0;
}