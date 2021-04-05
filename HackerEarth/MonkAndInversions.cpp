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
		int arr[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >>arr[i][j];
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int p = 0; p < n; p++){
					for(int q = 0; q < n; q++){
						if(arr[i][j] > arr[p][q] && i <= p && j <= q)
							ans++;
					}
				}
			}
		}
		cout <<ans <<"\n";
	}
	return 0;
}