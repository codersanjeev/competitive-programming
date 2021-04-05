#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >>t;
	while(t--){
		vector<int> arr(3);
		for(int i = 0; i < 3; i++)
			cin >>arr[i];
		sort(arr.begin(), arr.end());
		cout <<arr[1] <<"\n";
	}
	return 0;
}