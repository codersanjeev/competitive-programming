#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double x, y;
	cin >>x >>y;
	if((int)(x)%5 == 0 && (y - x - 0.5) > 0)
		cout <<setprecision(2) <<fixed <<y - x - 0.5 <<"\n";
	else
		cout <<setprecision(2) <<fixed <<y <<"\n";
	return 0;
}