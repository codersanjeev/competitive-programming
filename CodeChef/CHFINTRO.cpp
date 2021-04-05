/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r, ele;
    cin >>n >>r;
    while(n--){
    	cin >>ele;
    	if(ele < r)
    		cout <<"Bad boi\n";
    	else
    		cout <<"Good boi\n";
    }
	return 0;
}