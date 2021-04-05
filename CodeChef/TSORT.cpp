#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >>arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++)
		cout <<arr[i] <<"\n";
	return 0;
}