#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, m, x, y, ele;
	cin >>t;
	while(t--){
		bool arr[101];
		memset(arr, true, sizeof(arr));
		cin >>m >>x >>y;
		while(m--){
			cin >>ele;
			int low = ele - (x*y);
			int high = ele + (x*y);
			if(low < 0)
				low = 0;
			if(high > 100)
				high = 100;
			for(int i = low; i <= high; i++)
				arr[i] = false;
		}
		int ans = 0;
		for(int i = 1; i <= 100; i++){
			if(arr[i])
				ans++;
		}
		cout <<ans <<"\n";
	}
	return 0;
}