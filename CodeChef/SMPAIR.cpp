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
		vector<int> arr(n);
		for(int i = 0; i < n; i++)
			cin >>arr[i];
		sort(arr.begin(), arr.end());
		cout <<arr[0] + arr[1] <<"\n";
	}
	return 0;
}