#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, k, ele;
	cin >>t;
	while(t--){
		cin >>n >>k;
		while(n--){
			cin >>ele;
			if(k - ele >= 0){
				k -= ele;
				cout <<"1";
			}
			else
				cout <<"0";
		}
		cout <<"\n";
	}
	return 0;
}