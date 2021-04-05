#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >>t;
	while(t--){
		int n, v1, v2;
		cin >>n >>v1 >>v2;
		double x = (sqrt(2) * n) / (1.0 * v1);
		double y = (2.0 * n) / v2;
		if(x > y)
			cout <<"Elevator\n";
		else
			cout <<"Stairs\n";
	}
	return 0;
}