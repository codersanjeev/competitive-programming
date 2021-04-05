#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >>arr[i];
	int ans = 1;
	int temp = arr[0];
	for(int i = 1; i < n; i++){
		if(temp > arr[i])
			ans++;
		temp = arr[i];
	}
	cout <<ans <<"\n";
	return 0;
}