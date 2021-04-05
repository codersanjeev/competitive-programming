#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t;
	cin >>t;
	while(t--){
		cin >>n;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >>arr[i];
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i; j <= n; j++){
				long s = 0, p = 1;
				for(int k = i; k < j; k++){
					s += arr[k];
					p *= arr[k];
				}
				if(s == p)
					ans++;
			}
		}
		cout <<ans <<"\n";
	}
	return 0;
}