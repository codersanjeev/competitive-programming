#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, q;
	double p;
	cin >>t;
	double ans = 0.0;
	while(t--){
		cin >>q >>p;
		if(q > 1000)
			cout <<setprecision(6) <<fixed <<0.9 * q * p <<"\n";
		else
			cout <<setprecision(6) <<fixed <<q * p <<"\n";
	}
	return 0;
}