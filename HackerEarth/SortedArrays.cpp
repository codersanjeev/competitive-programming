#include<bits/stdc++.h>
using namespace std;

int main(){
	long n;
	cin >>n;
	long arr[n];
	for(long i = 0; i < n; i++)
		cin >>arr[i];
	long ans = 0;
	for(long i = 0; i < n-1; i++){
		if(arr[i+1] <= arr[i]){
			long diff = arr[i] - arr[i+1];
			ans = ans + diff + 1;
			arr[i+1] = arr[i+1] + diff + 1;
		}
	}
	cout <<ans;
	return 0;
}