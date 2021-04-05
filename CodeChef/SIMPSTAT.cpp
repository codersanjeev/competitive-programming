#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, k;
	cin >>t;
	while(t--){
		cin >>n >>k;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >>arr[i];
		sort(arr, arr+n);
		int s = 0;
		for(int i = k; i < n-k; i++)
			s += arr[i];
		cout <<setprecision(6) <<fixed <<s / (1.0 * (n - 2*k)) <<"\n";
	}
	return 0;
}