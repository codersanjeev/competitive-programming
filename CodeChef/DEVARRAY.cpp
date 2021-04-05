#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >>n >>q;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >>arr[i];
	int *mx = max_element(arr, arr+n);
	int *mn = min_element(arr, arr+n);
	while(q--){
		int ele;
		cin >>ele;
		if(ele >= *mn && ele <= *mx)
			cout <<"Yes\n";
		else
			cout <<"No\n";
	}
	return 0;
}