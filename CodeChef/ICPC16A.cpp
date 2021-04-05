#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, x1, y1, x2, y2;
	cin >>t;
	while(t--){
		cin >>x1 >>y1 >>x2 >>y2;
		if(x1 == x2){
			// up or down
			if(y2 > y1)
				cout <<"up\n";
			else
				cout <<"down\n";
		}
		else if(y1 == y2){
			// left or right
			if(x2 > x1)
				cout <<"right\n";
			else
				cout <<"left\n";
		}
		else{
			cout <<"sad\n";
		}
	}
	return 0;
}