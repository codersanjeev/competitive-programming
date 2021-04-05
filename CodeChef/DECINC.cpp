#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >>n;
	if(n%4 == 0)
		cout <<n+1;
	else
		cout <<n-1;
	return 0;
}