#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {

	ll j,s,m;
	cin>>j>>s>>m;
	ll amt=floor((m-j)/s);

	if(amt%2==0)
	cout<<"Lucky Chef\n";
	else
	cout<<"Unlucky Chef\n";

	return 0;
}
