#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, ele;
	cin >>t;
	while(t--){
		cin >>n;
		map<int, int> freq;
		for(int i = 0; i < n; i++){
			cin >>ele;
			freq[ele]++;
		}
		for(auto x : freq){
			if(x.second%2 == 1)
				cout <<x.first <<"\n";
		}
	}
	return 0;
}