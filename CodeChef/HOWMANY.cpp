#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >>s;
	if(s.size() < 4)
		cout <<s.size();
	else
		cout <<"More than 3 digits";
	return 0;
}