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
		int x[n], y[n];
		for(int i = 0; i < n; i++)
			cin >>x[i];
		for(int i = 0; i < n; i++)
			cin >>y[i];
		int a = 0, b = 0;
		for(int i = 0; i < n; i++){
			if(i%2 == 0){
				a += x[i];
				b += y[i];
			}
			else{
				a += y[i];
				b += x[i];
			}
		}
		cout <<min(a, b) <<"\n";
	}
	return 0;
}