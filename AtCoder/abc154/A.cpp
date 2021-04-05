/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string s, t, u;
	cin >>s >>t;
	int a, b;
	cin >>a >>b;
	cin >>u;
	if(u == s)
		cout <<a-1 <<" " <<b;
	else 
		cout <<a <<" " <<b-1;
	return 0;
}
