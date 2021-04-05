#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ele, even = 0, odd = 0;
	cin >>n;
	for(int i = 0; i < n; i++){
		cin >>ele;
		if(ele%2 == 0)
			even++;
		else
			odd++;
	}
	if(even > odd)
		cout <<"READY FOR BATTLE\n";
	else
		cout <<"NOT READY\n";
	return 0;
}