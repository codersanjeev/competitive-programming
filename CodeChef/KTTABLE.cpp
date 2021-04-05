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
		int a[n], b[n];
		for(int i = 0; i < n; i++)
			cin >>a[i];
		for(int i = 0; i < n; i++)
			cin >>b[i];
		for(int i = n-1; i >= 1; i--)
			a[i] -= a[i-1];
		int ans = 0;
		for(int i = 0; i < n; i++)
			if(a[i] >= b[i])
				ans++;
		cout <<ans <<"\n";
	}
	return 0;
}