#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	double a, b, c;
	cin >>t;
	while(t--){
		cin >>a >>b >>c;
		if(a > 50 && b < 0.7 && c > 5600)
			cout <<"10\n";
		else if(a > 50 && b < 0.7)
			cout <<"9\n";
		else if(b < 0.7 && c > 5600)
			cout <<"8\n";
		else if(a > 50 && c > 5600)
			cout <<"7\n";
		else if(a > 50 || b < 0.7 || c > 5600)
			cout <<"6\n";
		else
			cout <<"5\n";
	}
	return 0;
}