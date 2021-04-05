#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x, y;
	bool flag;
	int cumX = 0, cumY = 0;
	cin >>n;
	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
		cin >>x >>y;
		cumX += x;
		cumY += y;
		int diff = abs(cumX - cumY);
		if(diff > ans){
			ans = diff;
			flag = (x > y);
		}
	}
	if(flag){
		cout <<1 <<" " <<ans <<"\n";
	}
	else{
		cout <<2 <<" " <<ans <<"\n";
	}
	return 0;
}