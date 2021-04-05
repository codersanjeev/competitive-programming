#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >>t;
	while(t--){
		cin >>n;
		double hr, da;
		if(n < 1500){
			hr = 0.1 * n;
			da = 0.9 * n;
		}
		else{
			hr = 500;
			da = 0.98 * n;
		}
		cout <<setprecision(2) <<fixed <<n + hr + da <<"\n";
	}
	return 0;
}