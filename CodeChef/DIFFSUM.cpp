#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y;
	cin >>x >>y;
	if(x > y)
		cout <<x-y;
	else
		cout <<x+y;
	return 0;
}