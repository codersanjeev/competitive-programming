#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >>n;
	while(n != 0){
		vector<int> arr(n+1);
		arr[0] = 0;
		for(int i = 1; i <= n; i++)
			cin >>arr[i];
		vector<int> arr2(n+1);
		arr2[0] = 0;
		for(int i = 1; i <= n; i++){
			auto it = find(arr.begin(), arr.end(), i);
			arr2[i] = distance(arr.begin(), it);
		}
		if(arr == arr2)
			cout <<"ambiguous\n";
		else
			cout <<"not ambiguous\n";
		cin >>n;
	}
	return 0;
}