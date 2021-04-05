#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int l, b;
	cin >>l >>b;
	int area = l * b;
	int peri  = 2 * (l + b);
	if(area == peri){
		cout <<"Eq\n" <<area <<"\n";
	}
	else if(area > peri){
		cout <<"Area\n" <<area <<"\n";
	}
	else{
		cout <<"Peri\n" <<peri <<"\n";
	}
	return 0;
}