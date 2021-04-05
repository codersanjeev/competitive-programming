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
    int a, b, t, n, x, s;
    cin >>t;
    while(t--){
    	cin >>n >>x >>s;
    	while(s--){
    		cin >>a >>b;
    		if(a == x)
    			x = b;
    		else if(b == x)
    			x = a;
    	}
    	cout <<x <<"\n";
    }
    return 0;
}