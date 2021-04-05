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
		set<int> days;
		while(n--){
			cin >>ele;
			days.insert(ele);
		}
		cout <<days.size() <<"\n";
	}
	return 0;
}